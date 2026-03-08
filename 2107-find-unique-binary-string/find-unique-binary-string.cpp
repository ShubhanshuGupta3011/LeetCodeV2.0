class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums) {
        int n=nums.size();
        unordered_set<string> lookUp;
        string ans="";
        for(auto it:nums){
            lookUp.insert(it);
            ans+="0";
        }
        int i=0;
        while(i<=n){
            if(lookUp.count(ans)){
                ans[i]='1';
                i++;
            }else{
                return ans;
            }
        }
        return "";
    }
};