#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using vi = vector<int>;
using vll = vector<ll>;
using vpii = vector<pii>;
using vpll = vector<pll>;
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define sz(x) ((int)(x).size())
const int INF = 1e9 + 5;
const ll LINF = 4e18;
const int MOD = 1e9 + 7;
const int MOD2 = 998244353;

struct SegmentTree{
    struct Node {
        ll mini;
        ll maxi;
    };
    int n;
    vector<ll> arr;
    vector<Node> seg;

    SegmentTree(vector<ll>& num){
        arr = num;
        n = sz(arr);
        seg.resize(4*n);
        update(1,0,n-1);
    }

    void update(int node,int low,int high){
        if(low > high) return;
        if(low == high){
            seg[node].mini = arr[low];
            seg[node].maxi = arr[low];
            return;
        }
        int mid = (low+high)/2;
        update(2*node,low,mid);
        update(2*node+1,mid+1,high);
        seg[node].mini = min(seg[2*node].mini,seg[2*node+1].mini);
        seg[node].maxi = max(seg[2*node].maxi,seg[2*node+1].maxi);
    }

    ll minQuery(int node,int low,int high,int l,int r){
        if(low > high) return INF;
        if(low > r || high < l) return INF;
        if(l <= low && high <= r) return seg[node].mini;
        int mid = (low+high)/2;
        ll left = minQuery(2*node,low,mid,l,r);
        ll right = minQuery(2*node+1,mid+1,high,l,r);
        return min(left,right);
    }

    ll maxQuery(int node,int low,int high,int l,int r){
        if(low > high) return -INF;
        if(low > r || high < l) return -INF;
        if(l <= low && high <= r) return seg[node].maxi;
        int mid = (low+high)/2;
        ll left = maxQuery(2*node,low,mid,l,r);
        ll right = maxQuery(2*node+1,mid+1,high,l,r);
        return max(left,right);
    }
    
    ll getMini(int l,int r){
        return minQuery(1,0,n-1,l,r);
    }

    ll getMaxi(int l,int r){
        return maxQuery(1,0,n-1,l,r);
    }
};

struct WaveletTree {
    using ll = long long;

    struct Node {
        ll lo, hi;
        vector<int> cnt;
        vector<ll> sum, tot;
        int left = -1, right = -1;
    };

    vector<Node> tree;
    int root;

    int build(vector<ll>& a, ll lo, ll hi) {
        int id = tree.size();
        tree.push_back(Node{});
        
        tree[id].lo = lo;
        tree[id].hi = hi;

        int n = a.size();

        tree[id].cnt.resize(n + 1);
        tree[id].sum.resize(n + 1);
        tree[id].tot.resize(n + 1);

        if (lo == hi) {
            for (int i = 0; i < n; i++) {
                tree[id].cnt[i + 1] = i + 1;
                tree[id].sum[i + 1] = tree[id].tot[i + 1]
                    = tree[id].tot[i] + a[i];
            }
            return id;
        }

        ll mid = lo + (hi - lo) / 2;

        vector<ll> L, R;

        for (int i = 0; i < n; i++) {
            tree[id].tot[i + 1] = tree[id].tot[i] + a[i];

            if (a[i] <= mid) {
                tree[id].cnt[i + 1] = tree[id].cnt[i] + 1;
                tree[id].sum[i + 1] = tree[id].sum[i] + a[i];
                L.push_back(a[i]);
            } 
            else {
                tree[id].cnt[i + 1] = tree[id].cnt[i];
                tree[id].sum[i + 1] = tree[id].sum[i];
                R.push_back(a[i]);
            }
        }

        if (!L.empty())
            tree[id].left = build(L, lo, mid);

        if (!R.empty())
            tree[id].right = build(R, mid + 1, hi);

        return id;
    }

    WaveletTree(vector<ll>& a) {
        root = build(
            a,
            *min_element(a.begin(), a.end()),
            *max_element(a.begin(), a.end())
        );
    }

    ll sumSmallest(int l, int r, int k) {
        return small(root, l, r + 1, k);
    }

    ll small(int id, int l, int r, int k) {
        Node& p = tree[id];

        if (k == 0)
            return 0;

        if (p.lo == p.hi)
            return p.lo * k;

        int L = p.cnt[l];
        int R = p.cnt[r];

        int leftCount = R - L;

        if (k <= leftCount)
            return small(p.left, L, R, k);

        ll leftSum = p.sum[r] - p.sum[l];

        return leftSum +
               small(
                   p.right,
                   l - L,
                   r - R,
                   k - leftCount
               );
    }

    ll sumLargest(int l, int r, int k) {
        return large(root, l, r + 1, k);
    }

    ll large(int id, int l, int r, int k) {
        Node& p = tree[id];

        if (k == 0)
            return 0;

        if (p.lo == p.hi)
            return p.lo * k;

        int L = p.cnt[l];
        int R = p.cnt[r];

        int leftCount = R - L;
        int rightCount = (r - l) - leftCount;

        if (k <= rightCount)
            return large(p.right, l - L, r - R, k);

        ll total = p.tot[r] - p.tot[l];
        ll leftSum = p.sum[r] - p.sum[l];
        ll rightSum = total - leftSum;

        return rightSum +
               large(
                   p.left,
                   L,
                   R,
                   k - rightCount
               );
    }
};

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, int k, vector<vector<int>>& queries) {
        vector<ll> rem;
        vector<ll> quo;
        for(auto it:nums){
            rem.pb(it%k);
            quo.pb(it/k);
        }

        SegmentTree st(rem);
        WaveletTree wt(quo);

        vector<ll> ans;
        for(auto it:queries){
            int l = it[0];
            int r = it[1];
            if(st.getMini(l,r) != st.getMaxi(l,r)){
                ans.push_back(-1);
                continue;
            }
            int ele = r - l + 1;
            int k = (ele/2) + (ele&1);

            ll small = wt.sumSmallest(l,r,k);
            ll large = wt.sumLargest(l,r,k);

            ans.push_back(large-small);
        }
        return ans;
    }
};