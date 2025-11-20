class Solution {
public:
    int mod=1e9+7;
    vector<int> fact;
    vector<int> invfact;
    int add(int a,int b) {return (a+b)%mod;}
    int multi(int a,int b) {return (1ll*a*b)%mod;}
    int rearrangeSticks(int n, int k) {
        vector<vector<int>> dp(n+1,vector<int>(k+1,0));
        dp[1][1]=1;
        for(int i=2;i<dp.size();i++){
            for(int j=1;j<dp[0].size();j++){
                dp[i][j]=multi(i-1,dp[i-1][j]);
                dp[i][j]=add(dp[i][j],dp[i-1][j-1]);
            }
        }
        return dp[n][k];
    }
};