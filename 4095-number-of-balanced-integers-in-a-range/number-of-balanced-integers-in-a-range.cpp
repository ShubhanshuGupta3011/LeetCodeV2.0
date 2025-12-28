class Solution {
public:
    long long dp[20][2][181] = {-1};
    vector<int> digit;
    vector<int> empty;
    long long dfs(int index,int tight,int diff){
        if(index == digit.size()) return !diff;
        if(dp[index][tight][diff+90] != -1) return dp[index][tight][diff+90];
        int nextDigit = tight?digit[index]:9;
        long long ans = 0;
        for(int i=0;i<=nextDigit;i++){
            int newTight = (tight && (i==nextDigit));
            ans += dfs(index+1,newTight,diff+(2*(index%2) - 1)*i);
        }
        return dp[index][tight][diff+90] = ans;
    }
    long long helper(long long n){
        digit = empty;
        memset(dp, -1, sizeof(dp));
        while(n){
            digit.push_back(n%10);
            n=n/10;
        }
        reverse(digit.begin(),digit.end());
        return dfs(0,1,0);
    }
    long long countBalanced(long long low, long long high) {
        return helper(high)-helper(low-1);
    }
};