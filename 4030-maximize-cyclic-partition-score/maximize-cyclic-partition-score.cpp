class Solution {
public:
    vector<long long> getArray(vector<int>& nums, int j) {
        int n = nums.size();
        vector<long long> arr1;
        for (int i = j; i < n; i++) {
            arr1.push_back(1ll * nums[i]);
        }
        for (int i = 0; i < j; i++) {
            arr1.push_back(1ll * nums[i]);
        }
        return arr1;
    }

    long long NEG = -1e17;
    vector<vector<vector<vector<long long>>>> dp;

    long long solve(int index, int buy, int flag, vector<long long>& arr,
                    int k) {
        if (index >= (int)arr.size()) {
            return flag ? 0 : NEG;
        }
        if (k < 0)
            return 0;

        int b = (buy + 1) / 2;

        if (dp[index][b][flag][k] != NEG)
            return dp[index][b][flag][k];

        long long ans1, ans2, ans3;

        if (flag) {
            ans1 = 1ll * arr[index] + solve(index + 1, -1, 0, arr, k);
            ans2 = -1ll * arr[index] + solve(index + 1, 1, 0, arr, k);
            ans3 = solve(index + 1, 1, 1, arr, k);
        } else {
            ans1 = 1ll * buy * arr[index] + solve(index + 1, -1, 1, arr, k - 1);
            ans2 = 1ll * buy * arr[index] + solve(index + 1, 1, 1, arr, k - 1);
            ans3 = solve(index + 1, buy, 0, arr, k);
        }
        return dp[index][b][flag][k] = max({ans1, ans2, ans3});
    }

    long long helper(vector<long long>& arr, int k) {
        int n = arr.size();
        dp.assign(n, vector<vector<vector<long long>>>(
                         2, vector<vector<long long>>(
                                2, vector<long long>(k + 1, NEG))));

        return solve(0, -1, 1, arr, k - 1);
    }

    long long maximumScore(vector<int>& nums, int k) {
        int mini = 1e9 + 1;
        int minIndex = -1;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (mini > nums[i]) {
                mini = nums[i];
                minIndex = i;
            }
        }
        vector<long long> arr1 = getArray(nums, minIndex);
        vector<long long> arr2 = getArray(nums, minIndex + 1);
        long long ans1 = helper(arr1, k);
        long long ans2 = helper(arr2, k);
        return max(ans1, ans2);
    }
};