class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> big(n);
        vector<int> small(n);
        big[0] = nums[0];
        small[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            big[i] = max(big[i-1],nums[i]);
        }
        for(int i=n-2;i>=0;i--){
            small[i] = min(small[i+1],nums[i]);
        }
        for(int i=0;i<n;i++){
            if(big[i]-small[i] <= k) return i;
        }
        return -1;
    }
};