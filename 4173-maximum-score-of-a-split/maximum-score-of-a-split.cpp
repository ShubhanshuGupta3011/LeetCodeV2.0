class Solution {
public:
    long long maximumScore(vector<int>& nums) {
        long long total=0;
        for(auto it:nums){
            total+=it;
        }
        long long suffixMin = 1e18;
        long long ans=-1e18;
        for(int i=nums.size()-1;i>0;i--){
            suffixMin=min(suffixMin,1ll*nums[i]);
            total-=nums[i];
            ans=max(ans,total-suffixMin);
        }
        return ans;
    }
};