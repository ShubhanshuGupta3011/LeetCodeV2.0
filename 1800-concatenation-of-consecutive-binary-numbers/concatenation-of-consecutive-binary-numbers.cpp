class Solution {
public:
    int mod = 1e9 + 7;
    int add(int a, int b) { return (a + b) % mod; }
    int multi(int a, int b) { return (1ll * a * b) % mod; }
    int power(int x, int n) {
        if (n < 2)
            return n ? x : 1;
        int f = power(x, n % 2);
        int s = power(multi(x, x), n / 2);
        return multi(f, s);
    }
    int concatenatedBinary(int n) {
        vector<int> bits(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            bits[i] = 1 + bits[i / 2];
        }
        vector<int> previousBit(n + 1, 0);
        for (int i = n - 1; i >= 0; i--) {
            previousBit[i] = previousBit[i + 1] + bits[i + 1];
        }
        int ans = 0;
        for(int i=0;i<=n;i++){
            ans=add(ans,multi(i,power(2,previousBit[i])));
        }
        return ans;
    }
};