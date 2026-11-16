class Solution {
public:
    vector<int> segTree;

    void build(int id, int low, int high, vector<int>& nums) {
        if (low == high) {
            segTree[id] = nums[low];
            return;
        }
        int mid = (low + high) / 2;
        build(2*id+1, low, mid, nums);
        build(2*id+2, mid+1, high, nums);
        segTree[id] = segTree[2*id+1] & segTree[2*id+2];
    }

    int query(int id, int low, int high, int l, int r) {
        if (low > r || high < l) return -1; 
        if (l <= low && high <= r) return segTree[id];
        int mid = (low + high) / 2;
        int left  = query(2*id+1, low, mid, l, r);
        int right = query(2*id+2, mid+1, high, l, r); 
        return left & right;
    }

    long long countConsistent(vector<int>& nums) {
        int n = nums.size();
        segTree.assign(4*n, -1);
        build(0, 0, n-1, nums);

        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();

        for (int i = n-1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {

            int l = left[i] + 1, r = i, ans1 = i;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (query(0, 0, n-1, mid, i) == nums[i]) {
                    ans1 = mid;
                    r = mid - 1;
                } else l = mid + 1;
            }

            l = i; r = right[i] - 1;
            int ans2 = i;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (query(0, 0, n-1, i, mid) == nums[i]) {
                    ans2 = mid;
                    l = mid + 1;
                } else r = mid - 1;
            }

            ans += 1LL * (i - ans1 + 1) * (ans2 - i + 1);
        }
        return ans;
    }
};