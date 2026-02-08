#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    struct BIT {
        int size;
        vector<int> lic;  
        vector<int> cnt;   

        BIT(int n) {
            size = n + 1;
            lic.assign(size, 0);
            cnt.assign(size, 0);
        }

        void update(int idx, int length, int count) {
            idx++; 
            while (idx < size) {
                if (lic[idx] == length) {
                    cnt[idx] += count;
                } else if (lic[idx] < length) {
                    lic[idx] = length;
                    cnt[idx] = count;
                }
                idx += idx & -idx;
            }
        }

        pair<int,int> query(int idx) {
            int length = 0;
            int count = 0;
            idx++;  
            while (idx > 0) {
                if (lic[idx] == length) {
                    count += cnt[idx];
                } else if (lic[idx] > length) {
                    length = lic[idx];
                    count = cnt[idx];
                }
                idx -= idx & -idx;
            }
            return {length, count};
        }
    };

    int findNumberOfLIS(vector<int>& nums) {
        vector<int> temp = nums;
        sort(temp.begin(), temp.end());
        temp.erase(unique(temp.begin(), temp.end()), temp.end());
        int n = temp.size();
        BIT bit(n);
        int maxLen = 0;
        int total = 0;
        for (int num : nums) {
            int idx = lower_bound(temp.begin(), temp.end(), num) - temp.begin();
            auto [len, count] = bit.query(idx - 1);
            len += 1; 
            if (len == 1) count = 1;
            if (len == maxLen) {
                total += count;
            } else if (len > maxLen) {
                maxLen = len;
                total = count;
            }
            bit.update(idx, len, count);
        }
        return total;
    }
};
