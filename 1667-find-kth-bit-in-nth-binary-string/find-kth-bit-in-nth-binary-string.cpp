class Solution {
public:
    string helper(string s){
        string t = "";
        for(int i=s.size()-1;i>=0;i--){
            t+=(s[i]=='0'?'1':'0');
        }
        s += "1"+ t;
        return s;
    }
    char findKthBit(int n, int k) {
        string curr="0";
        for(int i=2;i<=n;i++){
            curr = helper(curr);
        }
        return curr[k-1];
    }
};