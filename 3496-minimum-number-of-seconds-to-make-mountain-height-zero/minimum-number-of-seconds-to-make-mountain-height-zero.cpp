class Solution {
public:
    long long solve(long long value){
        if (value == 0) return 0;
        return (long long)((sqrt(1 + 8.0 * value) - 1) / 2);
    }
    long long helper(vector<int>& workerTimes,long long mid){
        long long ans = 0;
        for(auto it:workerTimes){
            long long times = mid/it;
            ans += solve(times);
        }
        return ans;
    }
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        long long low = 1;
        long long high = 1e18;
        long long ans = -1;
        while(low <= high){
            long long mid = (low+high)/2;
            long long currMountainHeight = helper(workerTimes,mid);
            if(currMountainHeight >= mountainHeight){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};