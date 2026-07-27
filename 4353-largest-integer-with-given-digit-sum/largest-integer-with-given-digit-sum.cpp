class Solution {
public:
    string helper(int n,int s){
        if(n==0) return "";
        if(s>=9){
            return "9" + helper(n-1,s-9);
        }
        return to_string(s) + helper(n-1,0);
    }
    int largestInteger(int n, int s) {
        if(s > 9*n) return -1;
        string ans = helper(n,s);
        return stoi(ans);
    }
};