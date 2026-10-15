class Solution {
public:
    int mod = 1e9 + 7;
    int add(int a,int b){
        if(a+b>=mod){
            return a+b-mod;
        }
        return a+b;
    }
    int nCr(int n,int r,vector<vector<int>>& dp){
        if(n<r) return 0;
        if(r==0) return 1;
        if(dp[n][r] != -1) return dp[n][r];

        return dp[n][r] = add(nCr(n-1,r,dp),nCr(n-1,r-1,dp));
    }
    int countKReducibleNumbers(string s, int k) {
        vector<int> setbits(801,0);
        for(int i=1;i<801;i++){
            setbits[i] = setbits[i/2] + (i&1);
        }
        vector<int> level(801,0);
        for(int i=2;i<801;i++){
            level[i] = 1 + level[setbits[i]];
        }
        int n = s.size();
        vector<vector<int>> dp(n+5,vector<int>(n+5,-1));

        int beforeBit = 0;
        int ans = 0;

        for(int i=0;i<n;i++){
            if(s[i]=='0') continue;
            int N = n - 1 - i;
            for(int R=0;R<=N;R++){
                if((1 + level[R+beforeBit]) <= k){
                    ans = add(ans,nCr(N,R,dp));
                }
            }
            beforeBit++;
        }
        return ans-1;
    }
};