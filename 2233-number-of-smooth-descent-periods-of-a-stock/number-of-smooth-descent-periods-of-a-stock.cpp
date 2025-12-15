class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n,1);
        for(int i=1;i<n;i++){
            if((prices[i-1]-prices[i]) == 1){
                dp[i]=1+dp[i-1];
            }
        }
        long long ans=0;
        for(auto it:dp){
            ans+=it;
        }
        return ans;
    }
};