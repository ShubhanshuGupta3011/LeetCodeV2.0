class Solution {
public:
    string s;
    int dp[10][2][2][1024];
    int solve(int index,int tight,int leadingZero,int bitmask){
        if(index >= s.size()){
            return 1;
        }
        if(dp[index][tight][leadingZero][bitmask] != -1) return dp[index][tight][leadingZero][bitmask];
        int d = tight ? s[index]-'0': 9;
        int ans = 0;
        for(int i=0;i<=d;i++){
            int newTight = tight && (i==d);
            int newLeadingZero = leadingZero && !i;
            int currMask = pow(2,i);
            if(newLeadingZero){
                ans += solve(index+1,newTight,newLeadingZero,bitmask);
                continue;
            }
            if(currMask & bitmask) continue;
            ans += solve(index+1,newTight,newLeadingZero,bitmask+currMask);
        }
        return dp[index][tight][leadingZero][bitmask] = ans;
    }
    int countSpecialNumbers(int n) {
        s = to_string(n);
        memset(dp,-1,sizeof(dp));
        return solve(0,1,1,0)-1;
    }
};