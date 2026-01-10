class Solution {
public:
    vector<int> parent;
    int getParent(int n){
        if(n==parent[n]) return n;
        return parent[n] = getParent(parent[n]);
    }
    void unioned(int a,int b){
        a=getParent(a);
        b=getParent(b);
        parent[b]=a; 
    }
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        vector<vector<int>> graph;
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        for(auto it:edgeList){
            graph.push_back({it[2],it[0],it[1]});
        }
        sort(graph.rbegin(),graph.rend());
        vector<vector<int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i][2],queries[i][0],queries[i][1],i});
        }
        sort(q.rbegin(),q.rend());
        vector<bool> ans(queries.size(),false);
        while(q.size()){
            auto it = q.back();
            q.pop_back();
            while(graph.size()){
                auto itt = graph.back();
                if(itt[0] >= it[0]) break;
                graph.pop_back();
                unioned(itt[1],itt[2]);
            }
            int a=getParent(it[1]);
            int b=getParent(it[2]);
            ans[it[3]] = (a==b);
        }

        return ans;
    }
};