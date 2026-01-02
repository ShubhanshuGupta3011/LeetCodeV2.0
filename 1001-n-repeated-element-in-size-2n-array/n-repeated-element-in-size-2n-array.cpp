class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        for(int i=2;i<n;i++){
            if(nums[i]==nums[i-1]) return nums[i];
            if(nums[i]==nums[i-2]) return nums[i];
            if(nums[i-1]==nums[i-2]) return nums[i-1];
        }
        return nums[n-1];
    }
};