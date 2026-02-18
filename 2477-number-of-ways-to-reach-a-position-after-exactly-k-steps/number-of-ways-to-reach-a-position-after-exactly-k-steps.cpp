class Solution {
public:
    int mod = 1e9+7;
    int add(int a,int b){
        return (a+b)%mod;
    }
    int nCr(int n,int r,vector<vector<int>>& dp){
        if(n<r) return 0;
        if(r==0) return 1;
        if(dp[n][r] != -1) return dp[n][r];
        return dp[n][r] = add(nCr(n-1,r,dp),nCr(n-1,r-1,dp));
    }
    int numberOfWays(int start, int end, int k) {
        int diff = abs(start-end);
        if((diff & 1) ^ (k & 1)) return 0;
        int mini = start - k;
        int maxi = start + k;

        if(mini<=end && end<=maxi){
            int gap = (end - mini)/2;
            vector<vector<int>> dp(k+1,vector<int>(k+1,-1));
            return nCr(k,gap,dp);
        }
        return 0;
    }
};