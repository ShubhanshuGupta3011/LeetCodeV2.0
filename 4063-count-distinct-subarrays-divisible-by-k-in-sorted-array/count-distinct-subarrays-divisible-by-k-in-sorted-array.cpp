class Solution {
public:
    long long numGoodSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        reverse(nums.begin(), nums.end());
        vector<int> temp = nums;
        map<int, int> mp;
        map<pair<int, int>, int> mp2;
        mp[0] = 1;
        mp2[{0, -1}] = 1;
        int prefixSum = 0;
        long long ans = 0;
        for (int i = 0; i < n; i++) {
            prefixSum += nums[i];
            prefixSum = prefixSum % k;
            int myCount = mp2[{prefixSum, nums[i]}];
            int leftCount = mp[prefixSum];
            ans += leftCount;
            ans -= myCount;
            mp[prefixSum]++;
            mp2[{prefixSum, nums[i]}]++;
        }
        return ans;
    }
};