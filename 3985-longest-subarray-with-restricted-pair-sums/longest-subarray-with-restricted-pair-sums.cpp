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

template <typename T>
void print(const T& x) {
	cout << x << '\n';
}

template <typename T>
void print(const vector<T>& v) {
	for (auto &x : v)
		cout << x << ' ';
	cout << '\n';
}

template <typename T>
void print(const vector<vector<T>>& v) {
	for (auto &row : v)
		print(row);
}

template <typename T1, typename T2>
void print(const pair<T1, T2>& p) {
	cout << p.first << ' ' << p.second << '\n';
}

template <typename T>
void print(const set<T>& s) {
	for (auto &x : s)
		cout << x << ' ';
	cout << '\n';
}

template <typename T>
void print(const multiset<T>& s) {
	for (auto &x : s)
		cout << x << ' ';
	cout << '\n';
}

template <typename K, typename V>
void print(const map<K, V>& mp) {
	for (auto &[key, value] : mp)
		cout << key << " : " << value << '\n';
}

template <typename K, typename V>
void print(const unordered_map<K, V>& mp) {
	for (auto &[key, value] : mp)
		cout << key << " : " << value << '\n';
}

template <typename T>
void print(const unordered_set<T>& s) {
	for (auto &x : s)
		cout << x << ' ';
	cout << '\n';
}

template <typename T>
void print(queue<T> q) {
	while (!q.empty()) {
		cout << q.front() << ' ';
		q.pop();
	}
	cout << '\n';
}

template <typename T>
void print(stack<T> s) {
	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}
	cout << '\n';
}

template <typename T>
void print(priority_queue<T> pq) {
	while (!pq.empty()) {
		cout << pq.top() << ' ';
		pq.pop();
	}
	cout << '\n';
}


// ============================================================
// INPUT FUNCTIONS
// ============================================================

template <typename T>
void read(T& x) {
	cin >> x;
}

template <typename T>
void read(vector<T>& v) {
	for (auto &x : v)
		cin >> x;
}

template <typename T>
vector<T> read(int n) {
	vector<T> v(n);
	read(v);
	return v;
}


// ============================================================
// DEBUG
// ============================================================

#define LOCAL

#ifdef LOCAL

#define debug(x) cerr << #x << " = ", debug_print(x)

template <typename T>
void debug_print(const T& x) {
	cerr << x << '\n';
}

template <typename T>
void debug_print(const vector<T>& v) {
	cerr << "[ ";

	for (auto &x : v)
		cerr << x << ' ';

	cerr << "]\n";
}

template <typename T>
void debug_print(const vector<vector<T>>& v) {
	cerr << "[\n";

	for (auto &row : v) {
		cerr << "  [ ";

		for (auto &x : row)
			cerr << x << ' ';

		cerr << "]\n";
	}

	cerr << "]\n";
}

template <typename T1, typename T2>
void debug_print(const pair<T1, T2>& p) {
	cerr << "(" << p.first << ", " << p.second << ")\n";
}

template <typename T>
void debug_print(const set<T>& s) {
	cerr << "{ ";

	for (auto &x : s)
		cerr << x << ' ';

	cerr << "}\n";
}

template <typename T>
void debug_print(const multiset<T>& s) {
	cerr << "{ ";

	for (auto &x : s)
		cerr << x << ' ';

	cerr << "}\n";
}

template <typename K, typename V>
void debug_print(const map<K, V>& mp) {
	cerr << "{ ";

	for (auto &[key, value] : mp)
		cerr << key << ":" << value << ' ';

	cerr << "}\n";
}

template <typename K, typename V>
void debug_print(const unordered_map<K, V>& mp) {
	cerr << "{ ";

	for (auto &[key, value] : mp)
		cerr << key << ":" << value << ' ';

	cerr << "}\n";
}

#else

#define debug(x)

#endif

// ============================================================
// MAIN
// ============================================================

class Solution {
public:
    int n;
    int maxSubarray(vector<int>& nums) {
        n = sz(nums);
        int maxi = *max_element(all(nums));
        vector<vi> a(1+maxi);
        vector<vi> p(1+maxi);
        vi best(n,-1);

        for(int i=0; i<n; i++) {
            p[nums[i]].pb(i);
            for(int j=i+1; j<n; j++) {
                int add = nums[i] + nums[j];
                if(add>maxi) continue;
                a[add].pb(i);
                a[add].pb(j);
            }
        }
        for(int sum=0; sum<=maxi; sum++) {
            if(!sz(a[sum]) || !sz(p[sum])) continue;
            vi s,e;
            int nn = sz(p[sum]);

            for(int i=0; i<a[sum].size(); i++) {
                if(i&1) {
                    e.pb(a[sum][i]);
                } else {
                    s.pb(a[sum][i]);
                }
            }

            // before
            for(int i=0; i<sz(s); i++) {
                if(p[sum][0] > s[i]) continue;
                if(p[sum][nn-1] < s[i]) {
                    best[e[i]] = max(best[e[i]],p[sum][nn-1]);
                } else {
                    int index = lower_bound(all(p[sum]),s[i]) - p[sum].begin();
                    best[e[i]] = max(best[e[i]],p[sum][index-1]);
                }
            }
            // after
            for(int i=0; i<sz(e); i++) {
                if(p[sum].back() < e[i]) continue;
                if(p[sum][0] > e[i]) {
                    best[p[sum][0]] = max(best[p[sum][0]],s[i]);
                } else {
                    int index = upper_bound(all(p[sum]),e[i]) - p[sum].begin();
                    best[p[sum][index]] = max(best[p[sum][index]],s[i]);
                }
            }
            // middle
            for(int i=0;i<sz(e);i++){
                int l = lower_bound(all(p[sum]),e[i]) - p[sum].begin();
                int r = upper_bound(all(p[sum]),s[i]) - p[sum].begin();
                if(l<=r) continue;
                best[e[i]] = max(best[e[i]],s[i]);
            }
        }
        for(int i=1; i<n; i++) {
            best[i] = max(best[i],best[i-1]);
        }
        for(int i=0; i<n; i++) {
            best[i] = i- best[i];
        }
        return *max_element(all(best));
    }
};