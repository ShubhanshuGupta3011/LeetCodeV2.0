class Solution {
public:
    int helper(int n){
        string s=to_string(n);
        int ans=0;
        for(int i=1;i<s.size()-1;i++){
            if(s[i]>s[i-1] && s[i]>s[i+1]) ans++;
            if(s[i]<s[i-1] && s[i]<s[i+1]) ans++;
        }
        return ans;
    }
    int totalWaviness(int a, int b) {
        int ans=0;
        for(int i=a;i<=b;i++){
            ans+=helper(i);
        }
        return ans;
    }
};