class Solution {
public:
    vector<vector<int>> sparseTable;
    vector<int> Log;

    int query(int l, int r) {
        int ln = Log[r - l + 1];
        return sparseTable[ln][l] & sparseTable[ln][r - (1 << ln) + 1];
    }

    long long countConsistent(vector<int>& nums) {
        int n = nums.size();
        Log.assign(n + 1, -1);
        for (int i = 1; i <= n; i++) Log[i] = 1 + Log[i / 2];

        vector<int> left(n, -1), right(n, n);
        stack<int> st;

        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] > nums[i]) st.pop();
            left[i] = st.empty() ? -1 : st.top();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] >= nums[i]) st.pop();
            right[i] = st.empty() ? n : st.top();
            st.push(i);
        }

        sparseTable.assign(1 + Log[n], vector<int>());
        sparseTable[0] = nums;
        for (int i = 1; i < (int)sparseTable.size(); i++) {
            int len = 1 << i, half = len >> 1;
            for (int j = 0; j + len <= n; j++) {                
                sparseTable[i].push_back(
                    sparseTable[i-1][j] & sparseTable[i-1][j + half]  
                );
            }
        }

        long long ans = 0;
        for (int i = 0; i < n; i++) {
            int l = left[i] + 1, r = i, ans1 = i;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (query(mid, i) == nums[i]) { ans1 = mid; r = mid - 1; }
                else l = mid + 1;
            }

            l = i; r = right[i] - 1;
            int ans2 = i;
            while (l <= r) {
                int mid = (l + r) / 2;
                if (query(i, mid) == nums[i]) { ans2 = mid; l = mid + 1; }
                else r = mid - 1;
            }

            ans += 1LL * (i - ans1 + 1) * (ans2 - i + 1);
        }
        return ans;
    }
};