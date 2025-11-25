class Solution {
public:
    vector<long long> presum;
    int half;
    long long getpresum(int l,int r){
        int last = r-1;
        int first = l+half;
        return presum[last]-presum[first-1];
    }
    long long helper(int index,vector<int>& prices, vector<int>& strategy,int flag,vector<vector<long long>>& dp){
        if(index>=prices.size()) return 0;
        if(dp[index][flag] != -1) return dp[index][flag];
        long long nojump = 0,jump=0;
        int condition  = flag && (index+2*half) <= prices.size();
        if(condition){
            jump = getpresum(index,index+2*half) + helper(index+2*half,prices,strategy,0,dp);
        }
        nojump = 1ll*strategy[index]*prices[index] + helper(index+1,prices,strategy,flag,dp);
        return dp[index][flag] = condition ? max(jump,nojump) : nojump;
    }
    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {
        half=k/2;
        presum.push_back(prices[0]);
        for(int i=1;i<prices.size();i++){
            presum.push_back(prices[i]+presum[i-1]);
        }
        vector<vector<long long>> dp(prices.size(),vector<long long>(2,-1));
        return helper(0,prices,strategy,1,dp);
    }
};