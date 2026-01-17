class Solution {
public:
    int alternatingXOR(vector<int>& nums, int target1, int target2) {
        int MOD = 1e9 + 7;
        int n = nums.size();
        vector<int> pref(n + 1, 0);
        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i] ^ nums[i];
        }
        vector<long long> dp0(n + 1, 0), dp1(n + 1, 0);
        unordered_map<int, long long> cnt0, cnt1;
        dp1[0] = 1;
        cnt1[0] = 1;
        for (int i = 1; i <= n; i++) {
            int needT1 = pref[i] ^ target1;
            int needT2 = pref[i] ^ target2;
            if (cnt1.count(needT1))
                dp0[i] = cnt1[needT1];
            if (cnt0.count(needT2))
                dp1[i] = cnt0[needT2];
            cnt0[pref[i]] = (cnt0[pref[i]] + dp0[i]) % MOD;
            cnt1[pref[i]] = (cnt1[pref[i]] + dp1[i]) % MOD;
        }
        return (dp0[n] + dp1[n]) % MOD;
    }

};