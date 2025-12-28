class Solution {
public:
    int mod=1e9+7;
    int dp[101][2][11];
    int add(int a,int b){
        return (a+b)%mod;
    }
    int check(string s){
        for(int i=1;i<s.size();i++){
            int diff=abs(s[i]-s[i-1]);
            if(diff!=1) return 0;
        }
        return 1;
    }
    vector<int> digit;
    int dfs(int index,int tight,int preValue){
        if(index == digit.size()) return 1;
        if(dp[index][tight][preValue] != -1) return dp[index][tight][preValue];
        int nextDigit = tight ? digit[index]:9;
        int ans=0;
        for(int i=0;i<=nextDigit;i++){
            int nextTight = tight && (i==nextDigit);
            if(preValue == 10){
                ans=add(ans,dfs(index+1,nextTight,i?i:10));
            }else{
                int diff = abs(preValue-i);
                if(diff==1){
                    ans=add(ans,dfs(index+1,nextTight,i));
                }
            }
        }
        return dp[index][tight][preValue] = ans;
    }
    int helper(string s){
        while(digit.size()) digit.pop_back();
        for(auto it:s) digit.push_back(it-'0');
        memset(dp,-1,sizeof(dp));
        return dfs(0,1,10);
    }
    int countSteppingNumbers(string low, string high) {
        int ans = helper(high)-helper(low)+check(low);
        ans=add(ans,mod);
        return ans;
    }
};