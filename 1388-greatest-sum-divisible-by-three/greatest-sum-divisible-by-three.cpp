class Solution {
public:
    int getMod3(int n){
        n=n%3;
        if(n<0) return 3+n;
        return n;
    }
    int helper(int index,vector<int>& nums,int flag,vector<vector<int>>& dp){
        if(index>=nums.size()) return flag?-1e9:0;
        if(dp[index][flag] != -1) return dp[index][flag];
        int notake = helper(index+1,nums,flag,dp);
        int take = nums[index]+helper(index+1,nums,getMod3(flag-nums[index]),dp);
        return dp[index][flag] = max(take,notake);
    }
    int maxSumDivThree(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(),vector<int>(3,-1));
        return helper(0,nums,0,dp);
    }
};