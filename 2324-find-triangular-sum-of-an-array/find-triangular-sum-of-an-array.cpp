class Solution {
public:
    int mod = 10;
    int multi(int a,int b){
        return (a*b) % mod;
    }
    int add(int a,int b){
        return (a+b) % mod;
    }
    int nCr(int n,int r,vector<vector<int>>& dp){
        if(n <= r) return (n == r);
        if(r==0) return 1;
        if(dp[n][r] != -1) return dp[n][r];
        return dp[n][r] = add(nCr(n-1,r,dp) , nCr(n-1,r-1,dp));
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        int ans = 0;
        vector<vector<int>> dp(n,vector<int>(n,-1));
        for(int i=0;i<n;i++){
            int combination = nCr(n-1,i,dp);
            int value = nums[i];
            ans = add(ans,multi(combination,value));
        }
        return ans;
    }
};