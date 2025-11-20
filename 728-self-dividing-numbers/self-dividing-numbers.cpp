class Solution {
public:
    int helper(int n){
        string s=to_string(n);
        for(auto it:s){
            int value=it-'0';
            if(!value) return 0;
            if(n%value!=0) return 0;
        }
        return 1;
    }
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> ans;
        for(int i=left;i<=right;i++){
            if(helper(i)){
                ans.push_back(i);
            }
        }
        return ans;
    }
};