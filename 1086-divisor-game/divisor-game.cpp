class Solution {
public:
    set<int> getFactor(int n){
        set<int> st;
        for(int i=1;i<=sqrt(n);i++){
            if(n%i) continue;
            st.insert(i);
            st.insert(n/i);
        }
        st.erase(n);
        return st;
    }
    bool solve(int n,vector<int>& dp){
        if(n==1) return false; 
        if(dp[n] != -1) return dp[n];
        set<int> factor = getFactor(n);
        bool ans = false;
        for(auto it:factor){
            ans = ans || !solve(n-it,dp);
        }
        return dp[n] = ans;
    }
    bool divisorGame(int n) {
        vector<int> dp(n+1,-1);
        return solve(n,dp);
    }
};