class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        int ans=INT_MIN;
        sort(nums.begin(),nums.end());
        int low=0;
        int high=n-1;
        while(low<high){
            ans=max(ans,nums[low++]+nums[high--]);
        }
        if(n%2){
            low=0;
            high=n-2;
            while(low < high){
                ans=max(ans,nums[low++]+nums[high--]);
            }
            low=1;
            high=n-1;
            while(low < high){
                ans=max(ans,nums[low++]+nums[high--]);
            }
        }
        return ans;
    }
};