class Solution {
public:
    int helper(string s,int start){
        int n = s.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int value = s[i]-'0';
            if((value & 1) != ((start+i) & 1)){
                ans++;
            }
        }
        return ans;
    }
    int minOperations(string s) {
        return min(helper(s,0),helper(s,1));
    }
};