class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {
        unordered_map<string,int> freq;
        for(auto word:words){
            string key = "";
            for(auto it:word){
                key += it;
                if(key.size() == k){
                    freq[key]++;
                }
            }
        }
        int ans=0;
        for(auto it:freq){
            if(it.second!=1){
                ans++;
            }
        }
        return ans;
    }
};