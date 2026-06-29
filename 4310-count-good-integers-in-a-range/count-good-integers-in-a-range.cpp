class Solution {
public:
    int D;
    string s;
    long long dp[16][2][11];
    long long solve(int index,int tight,int prev){
        if(index == s.size()) return 1;
        if(dp[index][tight][prev] != -1) return dp[index][tight][prev];
        int d = tight ? s[index]-'0' : 9;
        long long ans = 0;
        for(int i=0;i<=d;i++){
            int newTight = tight && (i==d);
            if(prev == 10){
                if(i==0){
                    ans += solve(index+1,newTight,10);
                }else{
                    ans += solve(index+1,newTight,i);
                }
            }else{
                if(abs(prev-i) <= D){
                    ans += solve(index+1,newTight,i);
                }
            }
        }
        return dp[index][tight][prev] = ans;
    }
    long long helper(long long n){
        s = to_string(n);
        memset(dp, -1, sizeof(dp));
        return solve(0,1,10);
    }
    long long goodIntegers(long long l, long long r, int k) {
        D = k;
        return helper(r)-helper(l-1);
    }
};