using ll = long long;
class Solution {
public:
    int mod = 1e9 + 7;
    struct Node {
        ll sum;
        ll sqSum;
        Node() {
            sum = 0;
            sqSum = 0;
        }
    };
    vector<Node> seg;
    vector<ll> lazy;

    void push(int id, int start, int end) {
        if (lazy[id] == 0)
            return;
        int mid = (start + end) / 2;

        ll l1 = mid - start + 1;
        ll l2 = end - mid;

        if (start != end) {
            seg[2 * id].sqSum += l1 * lazy[id] * lazy[id];
            seg[2 * id].sqSum += 2 * seg[2 * id].sum * lazy[id];
            seg[2 * id].sum += lazy[id] * l1;
            lazy[2 * id] += lazy[id];

            seg[2 * id].sqSum %= mod;
            seg[2 * id].sum %= mod;
            lazy[2 * id] %= mod;

            seg[2 * id + 1].sqSum += l2 * lazy[id] * lazy[id];
            seg[2 * id + 1].sqSum += 2 * seg[2 * id + 1].sum * lazy[id];
            seg[2 * id + 1].sum += lazy[id] * l2;
            lazy[2 * id + 1] += lazy[id];

            seg[2 * id + 1].sqSum %= mod;
            seg[2 * id + 1].sum %= mod;
            lazy[2 * id + 1] %= mod;
        }
        lazy[id] = 0;
    }

    void update(int id, int start, int end, int l, int r, ll value) {
        if (start > r || end < l)
            return;
        ll len = end - start + 1;
        if (l <= start && end <= r) {
            seg[id].sqSum += value * value * len;
            seg[id].sqSum += 2 * seg[id].sum * value;
            seg[id].sum += value * len;

            seg[id].sqSum %= mod;
            seg[id].sum %= mod;
            lazy[id] += value;
            return;
        }
        push(id, start, end);

        int mid = (start + end) / 2;
        update(2 * id, start, mid, l, r, value);
        update(2 * id + 1, mid + 1, end, l, r, value);

        seg[id].sqSum = seg[2 * id].sqSum + seg[2 * id + 1].sqSum;
        seg[id].sum = seg[2 * id].sum + seg[2 * id + 1].sum;

        seg[id].sqSum %= mod;
        seg[id].sum %= mod;
    }

    ll getSum(int id, int start, int end, int l, int r) {
        if (start > r || end < l) {
            return 0;
        }

        push(id, start, end);
        if (l <= start && end <= r) {
            return seg[id].sqSum % mod;
        }
        int mid = (start + end) / 2;

        ll left = getSum(2 * id, start, mid, l, r) % mod;
        ll right = getSum(2 * id + 1, mid + 1, end, l, r) % mod;

        seg[id].sum = seg[2 * id].sum + seg[2 * id + 1].sum;
        seg[id].sqSum = seg[2 * id].sqSum + seg[2 * id + 1].sqSum;

        seg[id].sum %= mod;
        seg[id].sqSum %= mod;

        return (left + right) % mod;
    }

    int sumCounts(vector<int>& nums) {
        int n = nums.size();
        seg.resize(4 * n, Node());
        lazy.resize(4 * n);
        unordered_map<int, int> before;
        ll ans = 0;
        for (int i = 0; i < n; i++) {
            int j = -1;
            if (before.find(nums[i]) != before.end()) {
                j = before[nums[i]];
            }
            update(1, 0, n - 1, j + 1, i, 1);
            ans += getSum(1, 0, n - 1, 0, i);
            ans %= mod;
            before[nums[i]] = i;
        }
        return ans;
    }
};