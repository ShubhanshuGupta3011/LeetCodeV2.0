#define ll long long
class Solution {
public:
    int n;
    ll dp[1005][1005];
    ll solve(int i,int k,vector<ll>&p){
        if(k==0){if(i==0)return 0; else return LLONG_MAX/4;}
        if(i==0)return LLONG_MAX/4;
        if(dp[i][k]!=-1)return dp[i][k];
        ll ans=LLONG_MAX/4;
        for(int j=k-1;j<i;j++){
            ll sum=p[i]-p[j];
            
            ans=min(ans,
    (ll)((dp[j][k-1]!=-1)?dp[j][k-1]:solve(j,k-1,p))+(ll)(sum*(sum+1)/2));
        }
        return dp[i][k]=ans;
    }
    long long minPartitionScore(vector<int>& nums, int k) {
        n=nums.size();
        vector<ll>p(n+1,0);
        memset(dp,-1,sizeof(dp));
        for(int i=0;i<n;i++)p[i+1]=p[i]+nums[i];
        return solve(n,k,p);
    }
};