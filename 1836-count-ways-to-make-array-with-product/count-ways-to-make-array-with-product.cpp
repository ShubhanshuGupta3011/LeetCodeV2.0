class Solution {
public:
    int mod=1e9+7;
    int add(int a,int b){
        if(a+b >= mod) return a+b-mod;
        return a+b;
    }
    int multi(int a,int b){
        return (1ll*a*b)%mod;
    }
    vector<int> prime = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};
    int dp[10100][15] = {0};
    vector<int> generate(vector<int>& arr){
        vector<int> ans = arr;
        for(int i=1;i<15;i++){
            ans[i]=add(ans[i],arr[i-1]);
        }
        return ans;
    }
    int nCr(int n,int r){
        return dp[n][r];
    }
    int helper(int n,int k){
        int ans=1;
        for(auto it:prime){
            int fact=0;
            while(k%it == 0){
                k=k/it;
                fact++;
            }
            ans=multi(ans,nCr(fact+n-1,fact));
        }
        if(k!=1) ans=multi(ans,n);
        return ans;
    }
    vector<int> waysToFillArray(vector<vector<int>>& queries) {
        dp[0][0]=1;
        for(int i=1;i<10100;i++){
            for(int j=0;j<15;j++) dp[i][j] = dp[i-1][j];
            for(int j=1;j<15;j++) dp[i][j] = add(dp[i][j],dp[i-1][j-1]);
        }
        vector<int> ans;
        for(auto it:queries){
            ans.push_back(helper(it[0],it[1]));
        }
        return ans;
    }
};