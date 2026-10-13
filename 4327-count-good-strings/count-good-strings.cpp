class Solution {
public:
    int mod = 1e9 + 7;
    unordered_map<long long, int> dp;

    int add(int a, int b) { return (a + b) % mod; }
    int multi(int a, int b) { return (1ll * a * b) % mod; }
    int sub(int a, int b) { return (a - b + mod) % mod; }
    int square(int a) { return multi(a,a); }

    int fib(long long n){
        if(dp.find(n) != dp.end()) return dp[n];
        if(n&1){
            return dp[n] = add(square(fib(n/2)),square(fib((n+1)/2)));
        }
        return dp[n] = sub(fib(n+1),fib(n-1));
    }
    int countGoodStrings(long long n) {
        dp[0] = 0;
        dp[1] = 1;
        dp[2] = dp[0] + dp[1];
        return multi(2, fib(n));
    }
};