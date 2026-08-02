class Solution {
public:
    int mod = 1e9 + 7;
    int K;
    int add(int a,int b){
        return (a+b)>=mod?(a+b-mod):(a+b);
    }
    int helper(int n,int target,vector<vector<int>>& dp){
        if(n==0) return !target;
        if(dp[n][target] != -1) return dp[n][target];
        int ans=0;
        for(int i=1;i<=K;i++){
            if(i>target) break;
            ans=add(ans,helper(n-1,target-i,dp));
        }
        return dp[n][target] = ans;
    }
    int numRollsToTarget(int n, int k, int target) {
        if(target<n || target>n*k) return 0;
        vector<vector<int>> dp(n+1,vector<int>(target+1,-1));
        K=k;
        return helper(n,target,dp);
    }
};