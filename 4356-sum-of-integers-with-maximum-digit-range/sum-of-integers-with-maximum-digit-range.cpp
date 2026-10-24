class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        vector<int> sum(10,0);
        for(auto it:nums){
            int value = it;
            int large = 0;
            int small = 9;
            while(value){
                large = max(large,value % 10);
                small = min(small,value % 10);
                value = value/10;
            }
            sum[large - small] += it;
        }
        for(int i=9;i>=0;i--){
            if(sum[i]){
                return  sum[i];
            }
        }
        return 0;
    }
};