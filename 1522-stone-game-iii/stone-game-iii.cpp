class Solution {
public:
    int n;
    vector<long long> suffixSum;
    long long helper(int index,vector<int>& stoneValue,vector<long long>& dp){
        if(index>=stoneValue.size()) return 0;
        if(dp[index]!=-1e18) return dp[index];
        long long result = -1e18;
        for(int i=1;i<=3;i++){
            result = max(result,suffixSum[index] - helper(index+i,stoneValue,dp));
        }
        return dp[index] = result;
    }
    string stoneGameIII(vector<int>& stoneValue) {
        n = stoneValue.size();
        suffixSum.resize(n,0);
        suffixSum[n-1] = stoneValue[n-1];
        for(int i=n-2;i>=0;i--){
            suffixSum[i] = suffixSum[i+1] + stoneValue[i];
        }
        vector<long long> dp(n,-1e18);
        long long AliceSum = helper(0,stoneValue,dp);
        cout<<"AliceSum = "<<AliceSum<<endl;
        long long totalSum = 0;
        for(auto it:stoneValue){
            totalSum += it;
        } 
        if(2*AliceSum == totalSum) return "Tie";
        if(2*AliceSum > totalSum) return "Alice";
        return "Bob";
    }
};