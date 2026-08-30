class Solution {
public:
    vector<vector<int>> arr;
    void helper(int value,int maxi){
        unordered_map<int,int> umap;
        queue<pair<int,int>> q;
        q.push({value,0});
        while(q.size()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int dis = it.second;
            if(umap.count(node)) continue;
            umap[node] = dis;
            q.push({node/2,1+dis});
        }
        for(auto it:umap){
            q.push({it.first,it.second});
        }
        unordered_map<int,int> real;
        while(q.size()){
            auto it = q.front();
            q.pop();
            int node = it.first;
            int dis = it.second;
            if(node > maxi) continue;
            if(real.count(node)){
                if(real[node] < dis) continue;
            }
            real[node] = dis;
            q.push({2*node,1+dis});
        }
        vector<int> part;
        for(auto it:real){
            part.push_back(it.first);
            part.push_back(it.second);
        }
        arr.push_back(part);
    }
    int solve(int index,int sum,vector<vector<int>>& dp){
        if(sum<0) return 1e9;
        if(sum==0) return 0;
        if(index == arr.size()) return 1e9;
        if(dp[index][sum] != -1) return dp[index][sum];
        int ans = solve(1+index,sum,dp);
        for(int i=1;i<arr[index].size();i+=2){
            int dis = arr[index][i];
            int node = arr[index][i-1];
            ans = min(ans,dis + solve(index+1,sum-node,dp));
        }
        return dp[index][sum] = ans;
    }
    int minOperations(vector<int>& nums, int sum) {
        for(auto it:nums){
            helper(it,sum);
        }
        vector<vector<int>> dp(nums.size(),vector<int>(1+sum,-1));
        int ans = solve(0,sum,dp);
        return ans!=1e9 ? ans : -1;
    }
};