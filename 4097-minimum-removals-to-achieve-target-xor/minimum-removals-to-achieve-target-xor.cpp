class Solution {
public:
    map<pair<int,int>,int> dp;
    int helper(int index,vector<int>& nums, int target){
        if(index == nums.size()){
            return target ? 100 : 0;
        }
        if(dp.count({index,target})) return dp[{index,target}];
        int case1 = 1 + helper(1+index,nums,target);
        int case2 = helper(1+index,nums,target^nums[index]);
        return dp[{index,target}] = min(case1,case2);
    }
    int minRemovals(vector<int>& nums, int target) {
        int res = helper(0,nums,target);
        return res!=100 ? res : -1;
    }
};