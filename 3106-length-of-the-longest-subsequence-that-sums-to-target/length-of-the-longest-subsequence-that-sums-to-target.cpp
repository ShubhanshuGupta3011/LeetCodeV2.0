class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> dp(1+target,-1);
        dp[0] = 0;
        for(auto it:nums){
            for(int i=target;i>=it;i--){
                if(dp[i-it] == -1) continue;
                dp[i] = max(dp[i],1+dp[i-it]);
            }
        }
        return dp[target];
    }
};