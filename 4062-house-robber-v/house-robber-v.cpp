class Solution {
public:
    long long solve(int index,vector<int>& nums, vector<int>& colors,vector<long long>& dp){
        if(index >= nums.size()) return 0;
        if(dp[index]!=-1) return dp[index];
        long long take = nums[index];
        long long notake = solve(index+1,nums,colors,dp);
        bool last = (index==(nums.size()-1));
        if(!last){
            if(colors[index] == colors[1+index]){
                take += solve(index+2,nums,colors,dp);
            }else{
                take += solve(index+1,nums,colors,dp);
            }
        }
        return dp[index] = max(take,notake);
    }
    long long rob(vector<int>& nums, vector<int>& colors) {
        vector<long long> dp(nums.size(),-1);
        return solve(0,nums,colors,dp);
    }
};