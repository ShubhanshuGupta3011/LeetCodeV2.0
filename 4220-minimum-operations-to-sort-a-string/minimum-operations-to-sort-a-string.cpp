class Solution {
public:
    int isAlreadySorted(string s){
        for(int i=1;i<s.size();i++){
            if(s[i] < s[i-1]) return 0;
        }
        return 1;
    }
    int minOperations(string s) {
        int n = s.size();
        if(isAlreadySorted(s)) return 0;
        int firstIndexofMini = 0;
        int lastIndexofMaxi = 0;
        char mini = s[0];
        char maxi = s[0];
        for(int i=0;i<n;i++){
            if(mini > s[i]){
                mini = s[i];
                firstIndexofMini = i;
            }
            if(maxi <= s[i]){
                maxi = s[i];
                lastIndexofMaxi = i;
            }
        }
        if(mini==s[0] || maxi==s[n-1]) return 1;
        if(firstIndexofMini==(n-1) && lastIndexofMaxi==0){ 
            if(n==2) return -1;
            return 3;
        }
        return 2;
    }
};