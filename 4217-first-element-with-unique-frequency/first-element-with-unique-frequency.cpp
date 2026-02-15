class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto it:nums){
            freq[it]++;
        }
        unordered_map<int,int> freqFreq;
        for(auto it:freq){
            freqFreq[it.second]++;
        }
        for(auto it:nums){
            int f = freq[it];
            int value = freqFreq[f];
            if(value == 1){
                return it;
            }
        }
        return -1;
    }
};