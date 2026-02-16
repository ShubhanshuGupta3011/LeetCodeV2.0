class Solution {
public:
    vector<bool> subsequenceSumAfterCapping(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<bool> sum(k + 1, false);
        sum[0] = true;
        vector<bool> ans(n + 1, true);
        int i = 1;
        int j = 0;
        while (i <= n) {
            while (j < n && nums[j] < i) {
                int val = nums[j];
                for (int l = k; l >= 0; l--) {
                    if (l < val)
                        break;
                    if(!sum[l]){
                        sum[l] = sum[l - val];
                    }    
                }
                j++;
            }
            if (sum[k]) {
                break;
            }
            ans[i] = false;
            int rem = n - j;
            if (rem) {
                vector<int> remaning;
                for (int l = 1; l <= rem; l++) {
                    if (l * i > k)
                        break;
                    remaning.push_back(l * i);
                }
                for (auto it : remaning) {
                    if (sum[k - it]) {
                        ans[i] = true;
                        break;
                    }
                }
            }
            i++;
        }
        reverse(ans.begin(), ans.end());
        ans.pop_back();
        reverse(ans.begin(), ans.end());
        return ans;
    }
};