class Solution {
public:
    int setBit(int n){
        return n ? 1 + setBit(n&(n-1)) : 0;
    }
    vector<int> sortByBits(vector<int>& arr) {
        vector<int> num[15];
        for(auto it:arr){
            num[setBit(it)].push_back(it);
        }
        vector<int> ans;
        for(int i=0;i<15;i++){
            sort(num[i].begin(),num[i].end());
            for(auto it:num[i]){
                ans.push_back(it);
            }
        }
        return ans;
    }
};