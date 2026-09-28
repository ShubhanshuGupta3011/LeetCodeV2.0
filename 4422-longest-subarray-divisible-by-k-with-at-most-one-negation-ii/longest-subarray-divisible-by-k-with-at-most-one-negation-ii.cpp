#include <bits/stdc++.h>
using namespace std;

// ============================================================
// TYPES
// ============================================================

using ll = long long;
using ull = unsigned long long;
using ld = long double;

using pii = pair<int, int>;
using pll = pair<ll, ll>;

using vi = vector<int>;
using vii = vector<vi>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;

// ============================================================
// MACROS
// ============================================================

#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define pb push_back
#define eb emplace_back
#define lb lower_bound
#define ub upper_bound
#define sz(x) ((int)(x).size())

// ============================================================
// CONSTANTS
// ============================================================

const int INF = 1e9;
const ll LINF = 4e18;

const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

// ============================================================
// PRINT FUNCTIONS
// ============================================================

template <typename T> void print(const T& x) { cout << x << '\n'; }

template <typename T> void print(const vector<T>& v) {
    for (auto& x : v)
        cout << x << ' ';
    cout << '\n';
}

template <typename T> void print(const vector<vector<T>>& v) {
    for (auto& row : v)
        print(row);
}

template <typename T1, typename T2> void print(const pair<T1, T2>& p) {
    cout << p.first << ' ' << p.second << '\n';
}

template <typename T> void print(const set<T>& s) {
    for (auto& x : s)
        cout << x << ' ';
    cout << '\n';
}

template <typename T> void print(const multiset<T>& s) {
    for (auto& x : s)
        cout << x << ' ';
    cout << '\n';
}

template <typename K, typename V> void print(const map<K, V>& mp) {
    for (auto& [key, value] : mp)
        cout << key << " : " << value << '\n';
}

template <typename K, typename V> void print(const unordered_map<K, V>& mp) {
    for (auto& [key, value] : mp)
        cout << key << " : " << value << '\n';
}

template <typename T> void print(const unordered_set<T>& s) {
    for (auto& x : s)
        cout << x << ' ';
    cout << '\n';
}

template <typename T> void print(queue<T> q) {
    while (!q.empty()) {
        cout << q.front() << ' ';
        q.pop();
    }
    cout << '\n';
}

template <typename T> void print(stack<T> s) {
    while (!s.empty()) {
        cout << s.top() << ' ';
        s.pop();
    }
    cout << '\n';
}

template <typename T> void print(priority_queue<T> pq) {
    while (!pq.empty()) {
        cout << pq.top() << ' ';
        pq.pop();
    }
    cout << '\n';
}

// ============================================================
// DEBUG
// ============================================================

#define debug(x) cout << #x << " = ", debug_print(x)

template <typename T> void debug_print(const T& x) { cout << x << '\n'; }

template <typename T> void debug_print(const vector<T>& v) {
    cout << "[ ";

    for (auto& x : v)
        cout << x << ' ';

    cout << "]\n";
}

template <typename T> void debug_print(const vector<vector<T>>& v) {
    cout << "[\n";

    for (auto& row : v) {
        cout << "  [ ";

        for (auto& x : row)
            cout << x << ' ';

        cout << "]\n";
    }

    cout << "]\n";
}

template <typename T1, typename T2> void debug_print(const pair<T1, T2>& p) {
    cout << "(" << p.first << ", " << p.second << ")\n";
}

template <typename T> void debug_print(const set<T>& s) {
    cout << "{ ";

    for (auto& x : s)
        cout << x << ' ';

    cout << "}\n";
}

template <typename K, typename V> void debug_print(const map<K, V>& mp) {
    cout << "{ ";

    for (auto& [key, value] : mp)
        cout << key << ":" << value << ' ';

    cout << "}\n";
}
// ============================================================
// MAIN
// ============================================================

class Solution {
public:
    int longestSubarray(vector<int>& nums, int k) {
        int n = sz(nums);
        vii idx(k);
        vii neg(k);
        idx[0].pb(-1);
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            sum %= k;
            if (sum < 0) {
                sum += k;
            }
            idx[sum].pb(i);
            int j = -2 * nums[i];
            j %= k;
            if (j < 0) {
                j += k;
            }
            neg[j].pb(i);
        }
        int ans = 0;
        for (int i = 0; i < k; i++) {
            for (int j = 0; j < k; j++) {

                if (!sz(idx[i]) || !sz(idx[j]))
                    continue;

                if (i == j) {
                    ans = max(ans, idx[i].back() - idx[i][0]);
                    continue;
                }

                int rem = i - j;
                if (rem < 0) {
                    rem += k;
                }
                if (!sz(neg[rem]))
                    continue;

                int s = idx[i][0];
                int e = idx[j].back();
                if (s > e)
                    continue;

                int l = lb(all(neg[rem]), s) - neg[rem].begin();
                int r = ub(all(neg[rem]), e) - neg[rem].begin();

                if (l != sz(neg[rem])) {
                    if (neg[rem][l] == s) {
                        l++;
                    }
                }
                if (r > l) {
                    ans = max(ans, e - s);
                }
            }
        }
        return ans;
    }
};