class Solution {
public:
    int squareSum(int n){
        int ans = 0;
        while(n){
            ans += (n%10) * (n%10);
            n = n/10;
        }
        return ans;
    }
    bool helper(int n,vector<int>& dp){
        if(n >= 300) return helper(squareSum(n),dp);
        if(dp[n] != -1) return dp[n];
        dp[n] = 0;
        return dp[n] = helper(squareSum(n),dp);
    }
    bool isHappy(int n) {
        vector<int> dp(300,-1);
        dp[1] = 1;
        return helper(n,dp);
    }
};