class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int a=0;
        vector<bool> ans;
        for(auto it:nums){
            a=2*a+it;
            a=a%5;
            ans.push_back(a?false:true);
        }
        return ans;
    }
};