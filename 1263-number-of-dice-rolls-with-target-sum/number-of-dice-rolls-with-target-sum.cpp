class Solution {
public:
    int mod = 1e9 + 7;
    int add(int a, int b) { return (a + b) >= mod ? (a + b - mod) : (a + b); }
    int numRollsToTarget(int n, int k, int target) {
        if (target < n || target > n * k)
            return 0;
        vector<int> dp(1 + target, 0);
        dp[0] = 1;
        while (n--) {
            vector<int> currDp(1 + target, 0);
            for (int i = 1; i <= k; i++) {
                for (int j = 0; j <= target; j++) {
                    if (j + i > target)
                        break;
                    currDp[j + i] = add(currDp[j + i], dp[j]);
                }
            }
            dp = currDp;
        }
        return dp[target];
    }
};