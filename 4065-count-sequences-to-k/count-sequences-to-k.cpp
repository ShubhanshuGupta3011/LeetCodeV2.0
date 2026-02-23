class Solution {
public:
    int targetTwo, targetThree, targetFive;
    int n;
    int dp[20][80][40][40];
    vector<int> helper(long long n) {
        int two = 0, three = 0, five = 0;
        while (n % 2 == 0) {
            n = n / 2;
            two++;
        }
        while (n % 3 == 0) {
            n = n / 3;
            three++;
        }
        while (n % 5 == 0) {
            n = n / 5;
            five++;
        }
        if (n != 1)
            return {-1};
        return {two, three, five};
    }
    int solve(int index, int two, int three, int five, vector<int>& nums) {
        if (index == n) {
            return (targetTwo == two) && (targetThree == three) &&
                   (targetFive == five);
        }
        if (dp[index][40 + two][20 + three][20 + five] != -1)
            return dp[index][40 + two][20 + three][20 + five];
        int notake = solve(index + 1, two, three, five, nums);
        vector<int> it = helper(nums[index]);
        int take1 =
            solve(index + 1, two + it[0], three + it[1], five + it[2], nums);
        int take2 =
            solve(index + 1, two - it[0], three - it[1], five - it[2], nums);
        return dp[index][40 + two][20 + three][20 + five] =
                   notake + take1 + take2;
    }
    int countSequences(vector<int>& nums, long long k) {
        n = nums.size();
        vector<int> it = helper(k);
        if (it[0] == -1)
            return 0;
        targetTwo = it[0];
        targetThree = it[1];
        targetFive = it[2];
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0, 0, nums);
    }
};