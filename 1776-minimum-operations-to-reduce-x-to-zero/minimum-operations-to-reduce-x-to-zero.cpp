class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        /*
        1 1 4 2 3

        1 2 6 8 11
        11 10 9 5 3

        */
        int n = nums.size();
        long long sum = 0;
        int ans = 1e9;
        unordered_map<long long,int> preSum;
        preSum[sum] = -1;
        for(int i=0;i<n;i++){
            sum += nums[i];
            preSum[sum] = i;
            if(sum>x) break;
        }
        sum = 0;
        if(preSum.count(x)){
            ans = min(ans,1 + preSum[x]);
        }
        for(int i=0;i<n;i++){
            int j = n-1-i;
            sum+=nums[j];
            if(sum > x) break;
            long long rem = x - sum;
            if(preSum.count(rem)){
                int pos = preSum[rem];
                if(pos == j) continue;
                ans = min(ans,1+i+1+pos);
            }
        }
        return ans!=1e9?ans:-1;
    }
};