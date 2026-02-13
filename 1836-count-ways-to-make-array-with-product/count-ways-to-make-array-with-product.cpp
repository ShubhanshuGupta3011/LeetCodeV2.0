class Solution {
public:
    int MOD = 1e9 + 7;
    vector<int> fact;
    int multi(int a, int b) { return (1ll * a * b) % MOD; }
    int power(int x, int n) {
        if (n < 2) return n ? x : 1;
        int f = power(x, n % 2);
        int s = power(multi(x, x), n / 2);
        return multi(f, s);
    }
    int inverse(int n) { return power(n, MOD - 2); }
    int nCr(int n, int r) {
        cout<<"n = "<<n<<",";
        int ans = fact[n];
        ans = multi(ans, inverse(fact[r]));
        ans = multi(ans, inverse(fact[n - r]));
        return ans;
    }
    int helper(int n, int k) {
        int ans = 1;
        int pc = 0;
        while ((k % 2) == 0) {
            k = k / 2;
            pc++;
        }
        ans = multi(ans, nCr(pc + n - 1, n - 1));
        for (int i = 3; i <= sqrt(k); i += 2) {
            if (k % i) continue;
            pc = 0;
            while ((k % i) == 0) {
                k = k / i;
                pc++;
            }
            ans = multi(ans, nCr(pc + n - 1, n - 1));
        }
        if (k != 1) ans = multi(ans, n);
        return ans;
    }
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        fact.resize(10101, 1);
        for (int i = 1; i <= 10100; i++) {
            fact[i] = multi(fact[i - 1], i);
        }
        vector<int> ans;
        for (auto it : queries) {
            ans.push_back(helper(it[0], it[1]));
        }
        return ans;
    }
};