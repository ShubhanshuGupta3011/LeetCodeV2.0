class Solution {
public:
    vector<int> digit;
    vector<int> power;
    int dp[10][2][2][20][21];
    int dfs(int index,int tight,int lendingZero,int sum,int diff,int k){
        if(index == digit.size()){
            return !diff && !sum;
        }
        if(dp[index][tight][lendingZero][sum][diff+10] != -1) return dp[index][tight][lendingZero][sum][diff+10];
        int nextDigit = tight ? digit[index] : 9;
        int ans=0;
        for(int i=0;i<=nextDigit;i++){
            int nextTight = tight && i==nextDigit ;
            int nextLendingZero = lendingZero && !i ;
            int adding = i*power[index];
            int nextSum = (sum+adding)%k;
            if(nextLendingZero){
                ans += dfs(index+1,nextTight,nextLendingZero,nextSum,diff,k);
            }else{
                int add = (i%2)?1:-1;
                ans += dfs(index+1,nextTight,nextLendingZero,nextSum,diff+add,k);
            }
        }
        return dp[index][tight][lendingZero][sum][diff+10] = ans;
    }
    int helper(int n,int k){
        while(digit.size()){
            digit.pop_back();
        }
        while(power.size()){
            power.pop_back();
        }
        while(n){
            digit.push_back(n%10);
            n=n/10;
        }
        reverse(digit.begin(),digit.end());
        int fact=1;
        while(digit.size()!=power.size()){
            power.push_back(fact);
            if(fact>=1e9){
                break;
            }
            fact=10*fact;
        }
        reverse(power.begin(),power.end());
        memset(dp,-1,sizeof(dp));
        return dfs(0,1,1,0,0,k);
    }
    int numberOfBeautifulIntegers(int low, int high, int k) {
        power.push_back(1);
        return helper(high,k)-helper(low-1,k);
    }
};