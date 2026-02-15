class Solution {
public:
    int almostPalindromic(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int l = 2; l <= n; l++) {
            for (int i = 0; i <= n - l; i++) {
                int j = i + l - 1;
                if (l == 2) {
                    dp[i][j] = (s[i] == s[j]) ? 0 : 1;
                } 
                else {
                    if (s[i] == s[j]) {
                        dp[i][j] = dp[i+1][j-1];
                    } 
                    else {
                        dp[i][j] = 1 + min(dp[i+1][j], dp[i][j-1]);
                    }
                }
            }
        }
        
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){ 
                if(dp[i][j]<2){
                    ans=max(ans,j-i+1);
                }
            }
        }
        return ans;
    }
};