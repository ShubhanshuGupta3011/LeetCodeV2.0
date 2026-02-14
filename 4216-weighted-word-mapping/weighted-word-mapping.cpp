class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        map<int,char> mp1;
        for(char ch='a';ch<='z';ch++){
            mp1['z'-ch]=ch;
        }
        string ans="";
        for(auto it:words){
            int sum = 0;
            for(auto itt:it){
                sum+=weights[itt-'a'];
            }
            sum = sum%26;
            ans += mp1[sum];
        }
        return ans;
    }
};