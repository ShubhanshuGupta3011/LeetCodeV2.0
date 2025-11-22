class Solution {
public:
    int minimumFlips(int n) {
        string s="";
        while(n){
            if(n%2){
                s+="1";
            }else{
                s+="0";
            }
            n=n/2;
        }
        int ans=0;
        int i=0,j=s.size()-1;
        while(i<=j){
            if(s[i]!=s[j]){
                ans+=2;
            }
            i++; j--;
        }
        return ans;
    }
};