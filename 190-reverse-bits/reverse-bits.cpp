class Solution {
public:
    int reverseBits(int n) {
        vector<int> dp(32,0);
        long long fact = 1;
        for(int i=0;i<31;i++){
            if(fact & n){
                dp[i]=1;
            }
            fact = 2*fact;
        }
        reverse(dp.begin(),dp.end());
        int ans = 0;
        fact = 1;
        for(int i=0;i<31;i++){
            if(dp[i]){
                ans += fact;
            }
            fact = 2*fact;
        }
        return ans;
    }
};