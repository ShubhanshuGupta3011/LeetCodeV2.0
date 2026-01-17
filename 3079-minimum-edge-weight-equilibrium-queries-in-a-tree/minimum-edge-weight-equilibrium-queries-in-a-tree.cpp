class Solution {
public: 
    int LOG = 20;
    vector<int> depth;
    vector<vector<int>> up;
    int getLca(int u,int v){
        if(depth[u] < depth[v]) swap(u,v);
        int diff = depth[u]-depth[v];
        for(int i=0;i<LOG;i++){
            int mask = 1<<i;
            if(mask & diff){
                u = up[u][i];
            }
        }
        if(u==v) return u;
        for(int i=LOG-1;i>=0;i--){
            if(up[u][i] != up[v][i]){
                u=up[u][i];
                v=up[v][i];
            }
        }
        return up[u][0];
    }
    void dfs(int node,int parent,int currDepth,vector<vector<vector<int>>>& graph,vector<vector<int>>& freq){
        vector<int> currFreq = freq[node];
        up[node][0] = parent;
        depth[node] = currDepth;
        for(int i=1;i<LOG;i++){
            up[node][i] = up[ up[node][i-1] ][i-1];
        }
        for(auto it:graph[node]){
            int child = it[0];
            int weight = it[1];
            if(child == parent) continue;
            currFreq[weight]++;
            freq[child] = currFreq;
            dfs(child,node,1+currDepth,graph,freq);
            currFreq[weight]--;
        }
    }
    vector<int> minOperationsQueries(int n, vector<vector<int>>& edges, vector<vector<int>>& queries) {
        vector<vector<vector<int>>> graph(n);
        vector<int> root(27,0);
        vector<vector<int>> freq(n);
        depth.resize(n);
        up.resize(n);
        for(int i=0;i<n;i++){
            freq[i] = root;
            up[i].resize(20);
        }
        for(auto it:edges){
            int u = it[0];
            int v = it[1];
            int w = it[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        dfs(0,0,0,graph,freq);
        vector<int> ans;
        for(auto it:queries){
            int u = it[0];
            int v = it[1];
            int lca = getLca(u,v);
            vector<int> CurrentValue(27,0);
            for(int i=0;i<27;i++){
                CurrentValue[i]+=freq[u][i];
            }
            for(int i=0;i<27;i++){
                CurrentValue[i]+=freq[v][i];
            }
            for(int i=0;i<27;i++){
                CurrentValue[i]-=2*freq[lca][i];
            }
            int total = 0;
            int maxi = 0;
            for(auto it:CurrentValue){
                total+=it;
                maxi=max(maxi,it);
            }
            cout<<endl;
            ans.push_back(total-maxi);
        }
        return ans;
    }
};