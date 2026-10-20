class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        long long ans = 0;
        sort(nums.rbegin(),nums.rend());

        for(int i=0;i<k;i++){
            if(mul > i){
                ans += 1ll * (mul - i) * nums[i];
            }else{
                ans += nums[i];
            }
        }
        return ans;
    }
};