class Solution {
public:
    vector<bool> isPrime;
    vector<int> prime;

    void primeCal() {
        const int n = 200000;
        isPrime.assign(n + 1, 1);
        prime.clear();

        isPrime[0] = isPrime[1] = 0;

        for (int i = 2; i * i <= n; i++) {
            if (isPrime[i]) {
                for (int j = i * i; j <= n; j += i) {
                    isPrime[j] = 0;
                }
            }
        }

        for (int i = 2; i <= n; i++) {
            if (isPrime[i]) {
                prime.push_back(i);
            }
        }
    }

    int minOperations(vector<int>& nums) {
        primeCal();
        int ans = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (i % 2 == 0) {
                if (!isPrime[nums[i]]) {
                    int idx = lower_bound(prime.begin(), prime.end(), nums[i]) - prime.begin();
                    ans += prime[idx] - nums[i];
                }
            } else {
                if (isPrime[nums[i]]) {
                    if (nums[i] == 2) {
                        ans += 2; 
                    } else {
                        ans += 1; 
                    }
                }
            }
        }

        return ans;
    }
};