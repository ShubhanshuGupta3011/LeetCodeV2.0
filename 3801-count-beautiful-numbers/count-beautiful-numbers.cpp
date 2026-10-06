class Solution {
public:
    string s;
    int dp[10][2][2][82][82];
    int solving(int index,int tight,int leadingZero,int product,int currSum,int sum){
        if(currSum > sum) return 0;
        if(index == s.size()){
            return (currSum==sum) && !(product % sum);
        }
        if(dp[index][tight][leadingZero][product][currSum] != -1){
            return dp[index][tight][leadingZero][product][currSum];
        }
        int ans = 0;
        int d = tight ? s[index]-'0' : 9;
        for(int i=0;i<=d;i++){
            int newTight = (tight && (i==d));
            int newLeadingZero = (leadingZero && !i);

            if(newLeadingZero){
                ans += solving(index+1,newTight,1,1,0,sum);
            }else{
                ans += solving(index+1,newTight,0,(product * i)%sum,currSum + i,sum);
            }
        }
        dp[index][tight][leadingZero][product][currSum] = ans;
        return ans;
    }
    int solve(int n){
        s = to_string(n);
        int ans = 0;
        for(int i=1;i<=81;i++){
            memset(dp,-1,sizeof(dp));
            ans += solving(0,1,1,1,0,i);
        }
        return ans;
    }
    int beautifulNumbers(int l, int r) {
        return solve(r) - solve(l-1);
    }
};