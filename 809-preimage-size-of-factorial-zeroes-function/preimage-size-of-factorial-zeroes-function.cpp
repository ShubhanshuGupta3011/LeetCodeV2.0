class Solution {
public:
    long long helper(long long n){
        if(n<5) return 0;
        return n/5 + helper(n/5);
    }
    int preimageSizeFZF(int k) {
        long long low = 0, high = 1e18;
        while(low<=high){
            long long mid = (low+high)/2;
            long long value = helper(mid);
            if(value == k) return 5;
            if(value > k){
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return 0;
    }
};