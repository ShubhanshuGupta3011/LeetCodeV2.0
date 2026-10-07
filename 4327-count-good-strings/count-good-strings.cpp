class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<long long, int> dp;
    int add(int a, int b) { return (a + b) % mod; }
    int multi(int a, int b) { return (1ll * a * b) % mod; }
    int fib(long long n) {
        if (dp.count(n))
            return dp[n];
        long long n1 = (n / 2);
        long long n2 = n1 - 1;

        int a = multi(fib(n1), fib(n1));
        int b = multi(fib(n2), fib(n2));
        int c = multi(fib(n1), fib(n2));

        if (n & 1) {
            return dp[n] = add(multi(2, a), add(b, multi(2, c)));
        }

        return dp[n] = add(a, multi(2, c));
    }
    int countGoodStrings(long long n) {
        dp[0] = 0;
        dp[1] = 1;
        return multi(2, fib(n));
    }
};