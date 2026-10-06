class Solution {
public:
    using ll = long long;
    using vll = vector<ll>;
    using vvll = vector<vll>;
    using vvvll = vector<vvll>;
    ll solve(int index,int flag,int del,vector<int>& nums,vvvll& dp){
        if(index == nums.size()) return 0;

        if(dp[index][(1+flag)/2][del] != -1e18) return dp[index][(1+flag)/2][del];

        ll ans = flag * nums[index] + solve(index+1,-flag,del,nums,dp);

        if(del){
            ans = max(ans,solve(index+1,flag,0,nums,dp));
        }
        if(ans < 0){
            ans = 0;
        }
        return dp[index][(1+flag)/2][del] = ans;
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vvvll dp(n,vvll(2,vll(2,-1e18)));
        ll ans = -1e18;
        for(int i=0;i<n;i++){
            ll part = solve(i+1,-1,1,nums,dp);
            ans = max(ans,nums[i] + part);
        }
        return ans;
    }
};