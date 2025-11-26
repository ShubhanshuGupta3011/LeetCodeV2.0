class Solution {
public:
    int n,m;
    int mod=1e9+7;
    int add(int a,int b){
        return (a+b)%mod;
    }
    int getValueInsideMod(int n,int k){
        n=n%k;
        if(n>=0) return n;
        return k+n;
    }
    int isInside(int x,int y){
        return x>=0 && x<n && y>=0 && y<m;
    }
    int helper(int i,int j,int rem,int k,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        if(!isInside(i,j)) return 0;
        if(dp[i][j][rem] != -1) return dp[i][j][rem];
        if(i==0 && j==0){
            return !getValueInsideMod(rem-grid[0][0],k);
        }
        int nextRem = getValueInsideMod(rem-grid[i][j],k);
        int up = helper(i-1,j,nextRem,k,grid,dp);
        int left = helper(i,j-1,nextRem,k,grid,dp);
        return dp[i][j][rem] = add(up,left);
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        n=grid.size();
        m=grid[0].size();
        
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k,-1)));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                grid[i][j]=grid[i][j]%mod;
            }
        }
        return helper(n-1,m-1,0,k,grid,dp);
    }
};