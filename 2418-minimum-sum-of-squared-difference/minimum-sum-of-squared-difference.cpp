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
// MAIN
// ============================================================
class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = sz(nums1);
        vll diff(n);
        for(int i=0;i<n;i++){
            diff[i] = abs(nums2[i] - nums1[i]);
        }
        ll ans = 0;
        ll maxi = *max_element(all(diff));
        vll arr(1+maxi,0);
        for(auto it:diff){
            arr[abs(it)]++;
        }
        int k = k1+k2;
        for(int i=maxi;i>0;i--){
            if(!arr[i]) continue;
            if(arr[i] > k ){
                arr[i] -= k;
                arr[i-1] += k;
                k = 0;
                break;
            }else{
                k -= arr[i];
                arr[i-1] += arr[i];
                arr[i] = 0;
            }
        }
        for(ll i=0;i<=maxi;i++){
            if(!arr[i]) continue;
            ans += (i*i*arr[i]);
        }
        return ans;
    }
};