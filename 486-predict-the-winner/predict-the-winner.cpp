class Solution {
public:
    int helper(int i,int j,vector<int>& nums,vector<vector<int>>& dp){
        if(i>j) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int take1 = nums[i] - helper(i+1,j,nums,dp);
        int take2 = nums[j] - helper(i,j-1,nums,dp);
        return dp[i][j] = max(take1,take2);
    }
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int diff = helper(0,n-1,nums,dp);
        cout<<"diff = "<<diff<<endl;
        return diff>=0;
    }
};