class Solution {
public:
    string result(int i,int n){
        string ans = "";
        while(i){
            ans = to_string(i%2) + ans;
            i=i/2;
        }
        while(ans.size() < n){
            ans= "0" + ans;
        }
        return ans;
    }
    int helper(string s){
        int ans = 0;
        for(auto it:s){
            ans = 2*ans;
            ans += (it-'0');
        }
        return ans;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums.size();
        unordered_set<int> lookUp;
        for(auto it:nums){
            lookUp.insert(helper(it));
        }
        for(int i=0;i<=n;i++){
            if(lookUp.count(i)) continue;
            return result(i,n);
        }
        return "";
    }
};