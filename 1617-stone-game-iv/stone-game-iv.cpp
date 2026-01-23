class Solution {
public:
    bool isPerfectSquare(int n){
        int rootN = sqrt(n);
        return n==rootN*rootN;
    }
    bool helper(int n,vector<int>& dp){
        if(isPerfectSquare(n)) return 1;
        if(dp[n] != -1) return dp[n];
        bool res = false;
        for(int i=1;i<=sqrt(n);i++){
            res = res || !helper(n-i*i,dp);
        }
        return dp[n] = res;
    }
    bool winnerSquareGame(int n) {
        vector<int> dp(n+1,-1);
        return helper(n,dp);
    }
};