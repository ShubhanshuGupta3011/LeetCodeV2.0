class Solution {
public:
    vector<int> digit;
    vector<int> vis={0,0,0,0,0,0,0,0,0,0};
    int dp[11][2][2];
    int dfs(int index,int tight,int lendingZero){
        if(index == digit.size()){
            return 1;
        }
        int nextDigit = tight ? digit[index]:9;
        int ans = 0;
        for(int i=0;i<=nextDigit;i++){
            int nextTight = (tight && (i==nextDigit));
            int nextLendingDigit = (lendingZero && i==0);
            if(i || !lendingZero){
                if(vis[i]==0){
                    vis[i]=1;
                    ans += dfs(index+1,nextTight,nextLendingDigit);
                    vis[i]=0;
                }
            }else{
                ans += dfs(index+1,nextTight,nextLendingDigit);
            }            
        }
        return ans;
    }
    int countSpecialNumbers(int n) {
        while(n){
            digit.push_back(n%10);
            n=n/10;
        }
        reverse(digit.begin(),digit.end());
        return dfs(0,1,1)-1;
    }
};