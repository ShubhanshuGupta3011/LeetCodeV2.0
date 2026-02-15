#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    vector<vector<int>> graph;
    vector<int> depth;
    vector<int> tin, tout;
    vector<int> power;
    vector<int> bit;
    int timer = 0;

    vector<int> parent[20];

    /* ---------------- Fenwick Tree ---------------- */

    void fenwickUpdate(int i,int val){
        for(; i < (int)bit.size(); i += i&-i){
            bit[i] ^= val;
        }
    }

    int fenwickQuery(int i){
        int ans = 0;
        for(; i>0; i -= i&-i){
            ans ^= bit[i];
        }
        return ans;
    }

    /* ---------------- DFS + Euler Tour ---------------- */

    void dfs(int node,int par,int d){
        parent[0][node] = par;
        depth[node] = d;

        tin[node] = ++timer;

        for(auto it:graph[node]){
            if(it==par) continue;
            dfs(it,node,d+1);
        }

        tout[node] = timer;
    }

    /* ---------------- LCA ---------------- */

    int getLca(int u,int v){
        if(depth[u] < depth[v]) swap(u,v);

        int diff = depth[u] - depth[v];
        for(int i=0;i<20;i++){
            if(diff&(1<<i)){
                u = parent[i][u];
            }
        }

        if(u==v) return u;

        for(int i=19;i>=0;i--){
            if(parent[i][u]!=parent[i][v]){
                u = parent[i][u];
                v = parent[i][v];
            }
        }
        return parent[0][u];
    }

    /* ---------------- Fenwick subtree update ---------------- */

    void updateNode(int node,int diffXor){
        fenwickUpdate(tin[node], diffXor);
        fenwickUpdate(tout[node]+1, diffXor);
    }

    int getPreXor(int node){
        return fenwickQuery(tin[node]);
    }

    bool isPowerOfTwo(int x){
        return x && !(x&(x-1));
    }

    bool isPalindrome(int u,int v){
        int lca = getLca(u,v);

        int totalXor = getPreXor(u) ^ getPreXor(v);
        totalXor ^= power[s[lca]-'a'];

        return totalXor==0 || isPowerOfTwo(totalXor);
    }

    /* ---------------- Main Function ---------------- */

    vector<bool> palindromePath(
        int n,
        vector<vector<int>>& edges,
        string _s,
        vector<string>& queries
    ) {
        s = _s;

        graph.assign(n,{});
        depth.assign(n,0);
        tin.assign(n,0);
        tout.assign(n,0);
        power.assign(26,1);
        bit.assign(n+2,0);
        timer = 0;

        /* IMPORTANT FIX — resize parent table */
        for(int i=0;i<20;i++){
            parent[i].assign(n,0);
        }

        for(int i=1;i<26;i++){
            power[i] = 2*power[i-1];
        }

        for(auto &e:edges){
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        dfs(0,0,1);
        parent[0][0] = 0;   // safety for root

        /* build binary lifting table */
        for(int i=1;i<20;i++){
            for(int j=0;j<n;j++){
                parent[i][j] = parent[i-1][ parent[i-1][j] ];
            }
        }

        /* initial build */
        for(int i=0;i<n;i++){
            updateNode(i, power[s[i]-'a']);
        }

        vector<bool> ans;

        for(auto &it:queries){
            string a,b,c;
            stringstream ss(it);
            ss >> a >> b >> c;

            if(a=="query"){
                int u = stoi(b);
                int v = stoi(c);
                ans.push_back(isPalindrome(u,v));
            }
            else{
                int node = stoi(b);
                char after = c[0];

                if(s[node]!=after){
                    char before = s[node];
                    int diffXor = power[before-'a'] ^ power[after-'a'];
                    updateNode(node,diffXor);
                    s[node] = after;
                }
            }
        }

        return ans;
    }
};
