class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int> freq;
        for(auto it:nums){
            freq[it]++;
        }
        vector<vector<int>> bucket(1+n);
        for(auto it:freq){
            int number = it.first;
            int frequency = it.second;
            bucket[frequency].push_back(number);
        }
        vector<int> ans;
        for(int i=n;i>=0;i--){
            for(auto it:bucket[i]){
                ans.push_back(it);
                if(ans.size()==k) break;
            }
            if(ans.size()==k) break;
        }
        return ans;
    }
};