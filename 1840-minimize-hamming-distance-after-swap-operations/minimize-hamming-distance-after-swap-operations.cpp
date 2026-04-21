class Solution {
public:
    vector<int> parent;
    int getParent(int u){
        if(u == parent[u]) return u;
        return  parent[u] = getParent(parent[u]);
    }
    void unioned(int u,int v){
        u = getParent(u);
        v = getParent(v);
        parent[v] = u;
    }
    int helper(unordered_map<int,int>& a,unordered_map<int,int>& b){
        unordered_map<int,int> freq;
        for(auto it:a){
            freq[it.first] += it.second;
        }
        cout<<endl;
        for(auto it:b){
            freq[it.first] -= it.second;
        }
        int ans = 0;
        for(auto it:freq){
            ans += abs(it.second);
        }
        return ans/2;
    }
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        for(auto it:allowedSwaps){
            unioned(it[0],it[1]);
        }
        vector<unordered_map<int,int>> s(n);
        vector<unordered_map<int,int>> t(n);
        for(int i=0;i<n;i++){
            int key = getParent(i);
            s[key][source[i]]++;
            t[key][target[i]]++;
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            if(s[i].size() == 0) continue;
            ans += helper(s[i],t[i]);
        }
        return ans;
    }
};