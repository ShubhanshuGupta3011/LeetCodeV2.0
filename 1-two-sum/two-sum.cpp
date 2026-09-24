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
// DEBUG
// ============================================================

#define debug(x) cout << #x << " = ", debug_print(x)

template <typename T>
void debug_print(const T& x) {
    cout << x << '\n';
}

template <typename T>
void debug_print(const vector<T>& v) {
    cout << "[ ";

    for (auto &x : v)
        cout << x << ' ';

    cout << "]\n";
}

template <typename T>
void debug_print(const vector<vector<T>>& v) {
    cout << "[\n";

    for (auto &row : v) {
        cout << "  [ ";

        for (auto &x : row)
            cout << x << ' ';

        cout << "]\n";
    }

    cout << "]\n";
}

template <typename T1, typename T2>
void debug_print(const pair<T1, T2>& p) {
    cout << "(" << p.first << ", " << p.second << ")\n";
}

template <typename T>
void debug_print(const set<T>& s) {
    cout << "{ ";

    for (auto &x : s)
        cout << x << ' ';

    cout << "}\n";
}

template <typename K, typename V>
void debug_print(const map<K, V>& mp) {
    cout << "{ ";

    for (auto &[key, value] : mp)
        cout << key << ":" << value << ' ';

    cout << "}\n";
}


// ============================================================
// MATH
// ============================================================

ll power(ll a, ll b, ll mod = MOD) {

	ll res = 1;

	a %= mod;

	while (b) {

		if (b & 1)
			res = res * a % mod;

		a = a * a % mod;

		b >>= 1;
	}

	return res;
}


ll gcdll(ll a, ll b) {
	return b ? gcdll(b, a % b) : abs(a);
}


ll lcmll(ll a, ll b) {
	return a / gcdll(a, b) * b;
}


ll extended_gcd(ll a, ll b, ll &x, ll &y) {

	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}

	ll x1, y1;

	ll g = extended_gcd(b, a % b, x1, y1);

	x = y1;
	y = x1 - (a / b) * y1;

	return g;
}


ll modInverse(ll a, ll mod = MOD) {
	return power(a, mod - 2, mod);
}


// ============================================================
// PRIME / SIEVE
// ============================================================

bool isPrime(ll n) {

	if (n < 2)
		return false;

	if (n % 2 == 0)
		return n == 2;

	for (ll i = 3; i * i <= n; i += 2) {

		if (n % i == 0)
			return false;
	}

	return true;
}


vector<int> sieve(int n) {

	vector<int> prime(n + 1, true);

	if (n >= 0)
		prime[0] = false;

	if (n >= 1)
		prime[1] = false;

	for (int i = 2; i * i <= n; i++) {

		if (!prime[i])
			continue;

		for (int j = i * i; j <= n; j += i)
			prime[j] = false;
	}

	return prime;
}


// ============================================================
// FACTORIAL / nCr
// ============================================================

vector<ll> fact;
vector<ll> invFact;
void init_factorial(int n) {

	fact.resize(n + 1);
	invFact.resize(1+n);

	fact[0] = 1;

	for (int i = 1; i <= n; i++)
		fact[i] = fact[i - 1] * i % MOD;

	invFact[n] = modInverse(fact[n]);

	for(int i=n-1; i>=0; i--)
		invFact[i] = invFact[i+1] * (1+i) % MOD;
}


ll nCr(int n, int r) {

	if (r < 0 || r > n)
		return 0;

	return fact[n]
	       * invFact[r] % MOD
	       * invFact[n-r] % MOD;
}


// ============================================================
// FENWICK TREE
// ============================================================

template <typename T>
struct Fenwick {

	int n;
	vector<T> bit;

	Fenwick(int n) {

		this->n = n;
		bit.assign(n + 1, 0);
	}

	void add(int index, T value) {

		for (; index <= n; index += index & -index)
			bit[index] += value;
	}

	T sum(int index) {

		T res = 0;

		for (; index > 0; index -= index & -index)
			res += bit[index];

		return res;
	}

	T query(int l, int r) {

		if (l > r)
			return 0;

		return sum(r) - sum(l - 1);
	}

	int kth(T k) {

		if (k <= 0)
			return 0;

		int pos = 0;
		T cur = 0;

		int pw = 1;

		while ((pw << 1) <= n)
			pw <<= 1;

		for (; pw; pw >>= 1) {

			int next = pos + pw;

			if (next <= n &&
			        cur + bit[next] < k) {

				pos = next;
				cur += bit[next];
			}
		}

		return pos + 1;
	}
};


// ============================================================
// SEGMENT TREE
// RANGE SUM + POINT UPDATE
// ============================================================

template <typename T>
struct SegmentTree {

	int n;
	vector<T> tree;

	SegmentTree(vector<T>& a) {

		n = a.size();

		tree.resize(4 * n);

		build(1, 0, n - 1, a);
	}

	void build(int node,
	           int l,
	           int r,
	           vector<T>& a) {

		if (l == r) {
			tree[node] = a[l];
			return;
		}

		int mid = (l + r) >> 1;

		build(node << 1,
		      l,
		      mid,
		      a);

		build(node << 1 | 1,
		      mid + 1,
		      r,
		      a);

		tree[node] =
		    tree[node << 1] +
		    tree[node << 1 | 1];
	}

	void update(int node,
	            int l,
	            int r,
	            int index,
	            T value) {

		if (l == r) {
			tree[node] = value;
			return;
		}

		int mid = (l + r) >> 1;

		if (index <= mid) {

			update(node << 1,
			       l,
			       mid,
			       index,
			       value);

		} else {

			update(node << 1 | 1,
			       mid + 1,
			       r,
			       index,
			       value);
		}

		tree[node] =
		    tree[node << 1] +
		    tree[node << 1 | 1];
	}

	void update(int index, T value) {

		update(1,
		       0,
		       n - 1,
		       index,
		       value);
	}

	T query(int node,
	        int l,
	        int r,
	        int ql,
	        int qr) {

		if (qr < l || r < ql)
			return 0;

		if (ql <= l && r <= qr)
			return tree[node];

		int mid = (l + r) >> 1;

		return query(node << 1,
		             l,
		             mid,
		             ql,
		             qr)
		       +
		       query(node << 1 | 1,
		             mid + 1,
		             r,
		             ql,
		             qr);
	}

	T query(int l, int r) {

		return query(1,
		             0,
		             n - 1,
		             l,
		             r);
	}
};

// ============================================================
// DSU
// ============================================================

struct DSU {

	vector<int> parent;
	vector<int> size;

	DSU(int n) {

		parent.resize(n);

		size.assign(n, 1);

		iota(all(parent), 0);
	}

	int find(int x) {

		if (parent[x] == x)
			return x;

		return parent[x] =
		           find(parent[x]);
	}

	bool unite(int a, int b) {

		a = find(a);
		b = find(b);

		if (a == b)
			return false;

		if (size[a] < size[b])
			swap(a, b);

		parent[b] = a;
		size[a] += size[b];

		return true;
	}

	bool same(int a, int b) {

		return find(a) == find(b);
	}
};



// ============================================================
// MonotonicStack
// ============================================================

struct MonotonicStack{
    vi nums;
    int n;
    MonotonicStack(vi arr){
        nums = arr;
        n = sz(arr);
    }
    vi getNextGreaterOnRight(){
        vi ans(n,n);
        vi temp;
        for(int i=0;i<n;i++){
            while(sz(temp) && nums[i] > nums[temp.back()]){
                ans[temp.back()] = i;
                temp.pop_back();
            }
            temp.pb(i);
        }
        return ans;
    }
    vi getNextSmallerOnRight(){
        vi ans(n,n);
        vi temp;
        for(int i=0;i<n;i++){
            while(sz(temp) && nums[i] < nums[temp.back()]){
                ans[temp.back()] = i;
                temp.pop_back();
            }
            temp.pb(i);
        }
        return ans;
    }
    vi getNextGreaterOnLeft(){
        vi ans(n,-1);
        vi temp;
        for(int i=0;i<n;i++){
            while(sz(temp) && nums[i] >= nums[temp.back()]){
                temp.pop_back();
            }
            if(sz(temp)){
                ans[i] = temp.back();
            }
            temp.pb(i);
        }
        return ans;
    }
    vi getNextSmallerOnLeft(){
        vi ans(n,-1);
        vi temp;
        for(int i=0;i<n;i++){
            while(sz(temp) && nums[i] <= nums[temp.back()]){
                temp.pop_back();
            }
            if(sz(temp)){
                ans[i] = temp.back();
            }
            temp.pb(i);
        }
        return ans;
    }
};

// ============================================================
// KMP
// ============================================================

struct KMP {

    vector<int> buildLPS(string& pattern) {
        int n = pattern.size();
        vector<int> lps(n);
        for (int i = 1, j = 0; i < n; ) {
            if (pattern[i] == pattern[j]) {
                lps[i++] = ++j;
            } else if (j) {
                j = lps[j - 1];
            } else {
                lps[i++] = 0;
            }
        }
        return lps;
    }


    vector<int> search(string& text, string& pattern) {
        vector<int> lps = buildLPS(pattern);
        vector<int> ans;
        int n = text.size();
        int m = pattern.size();
        for (int i = 0, j = 0; i < n; ) {
            if (text[i] == pattern[j]) {
                i++;
                j++;
                if (j == m) {
                    ans.push_back(i - m);
                    j = lps[j - 1];
                }
            } else if (j) {
                j = lps[j - 1];
            } else {
                i++;
            }
        }
        return ans;
    }
};

// ============================================================
// MAIN
// ============================================================

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vi ans;
        int n = sz(nums);
        debug(nums);
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(nums[i] + nums[j] == target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};