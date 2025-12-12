class Solution {
public:
    int res=0;
    int dfs(int node,int parent,vector<vector<int>>& adj,vector<long long>& costs){
        vector<long long> arr;
        for(auto it:adj[node]){
            if(it!=parent){
                dfs(it,node,adj,costs);
            }
        }
        for(auto it:adj[node]){
            if(it!=parent){
                arr.push_back(costs[it]);   
            }
        }
        long long maxi=0;
        for(auto it:arr){
            maxi=max(maxi,it);
        }
        int ans=0;
        for(auto it:arr){
            if(it!=maxi){
                ans++;
            }
        }
        // cout<<"node = "<<node<<endl;
        // for(auto it:arr){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        costs[node] += maxi;
        
        // cout<<"cost = ";
        // for(auto it:costs){
        //     cout<<it<<" ";
        // }
        // cout<<endl;
        res+=ans;
        return ans;
    }
    int minIncrease(int n, vector<vector<int>>& edges, vector<int>& cost) {
        vector<long long> costs ;
        for(auto it:cost){
            costs.push_back(it);
        }
        vector<vector<int>> adj(n);
        for(auto it:edges){
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        dfs(0,-1,adj,costs);
        return res;
    }
};