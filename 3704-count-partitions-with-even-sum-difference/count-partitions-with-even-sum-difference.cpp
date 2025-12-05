class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int sum=0;
        for(auto it:nums) sum+=it;
        if(sum%2) return 0;
        return nums.size()-1;
    }
};