class Solution {
public:
    int n;
    vector<int> suffixSum;
    int helper(int index,int M,vector<int>& piles,vector<vector<int>>& dp){
        if(index>=piles.size()) return 0;
        if(index+2*M >= piles.size()) return suffixSum[index];
        if(dp[index][M] != -1) return dp[index][M];
        int result=0;
        for(int i=1;i<=2*M;i++){
            result = max(result,suffixSum[index] - helper(index+i,max(M,i),piles,dp));
        }
        return dp[index][M] = result;
    }
    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suffixSum.resize(n,0);
        suffixSum[n-1] = piles[n-1];
        for(int i=n-2;i>=0;i--){
            suffixSum[i] = suffixSum[i+1] + piles[i];
        }
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return helper(0,1,piles,dp);
    }
};