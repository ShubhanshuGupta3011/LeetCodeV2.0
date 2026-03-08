class Solution {
public:
    string result(int i,int n){
        cout<<"i = "<<i<<" n = "<<n<<endl;
        string ans = "";
        while(i){
            if(i%2){
                ans = "1" + ans;
            }else{
                ans = "0" + ans;
            }
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