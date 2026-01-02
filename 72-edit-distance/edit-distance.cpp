class Solution {
public:
    int dp[501][501];
    int helper(int i,int j,string s,string t){
        if(i==s.size() && j==t.size()) return 0;
        if(i==s.size()){
            return 1+helper(i,j+1,s,t);
        }
        if(j==t.size()){
            return 1+helper(i+1,j,s,t);
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int case1=1e9,case2=1e9,case3=1e9;
        case1 = helper(i+1,j+1,s,t) + (s[i]!=t[j]);
        case2 = helper(i+1,j,s,t) + 1;
        case3 = helper(i,j+1,s,t) + 1;
        return dp[i][j]=min(case1,min(case2,case3));
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return helper(0,0,word1,word2);
    }
};