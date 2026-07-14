class Solution {
public:
    int n,m;
    int helper(int prev,int index,vector<vector<int>>& grid, int limit,vector<vector<int>>& dp){
        if(index == m) return 0;
        int notake = 0;
        int take = 0;
        if(dp[1+prev][1+index] != -1) return dp[1+prev][1+index];
        if(prev == -1){
            take = 1 + helper(index,index+1,grid,limit,dp);
            notake = helper(prev,index+1,grid,limit,dp);
        }else{
            notake = helper(prev,index+1,grid,limit,dp);
            int flag = 1;
            for(int i=0;i<n;i++){
                if(abs(grid[i][prev]-grid[i][index]) > limit){
                    flag = 0;
                    break;
                }
            }
            if(flag){
                take = 1 + helper(index,index+1,grid,limit,dp);
            }
        }

        return dp[1+prev][1+index] = max(take,notake);
    }
    int maxConsistentColumns(vector<vector<int>>& grid, int limit) {
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>> dp(2+m,vector<int>(2+m,-1));
        return helper(-1,0,grid,limit,dp);
    }
};