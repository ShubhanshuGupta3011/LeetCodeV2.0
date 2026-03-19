class Solution {
public:
    int getIndex(char ch){
        if(ch=='X') return 0;
        if(ch=='Y') return 1;
        return 2;
    }
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(3,0)));

        for(int i=0;i<n;i++){
            int index = getIndex(grid[i][0]);
            dp[i][0][index] = 1;
        }
        
        for(int i=0;i<n;i++){
            for(int j=1;j<m;j++){
                int index = getIndex(grid[i][j]);
                dp[i][j][index]++;
                dp[i][j][0] += dp[i][j-1][0];
                dp[i][j][1] += dp[i][j-1][1];
                dp[i][j][2] += dp[i][j-1][2];
            }
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                dp[i][j][0] += dp[i-1][j][0];
                dp[i][j][1] += dp[i-1][j][1];
                dp[i][j][2] += dp[i-1][j][2];
            }
        }
        int ans = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dp[i][j][0] && dp[i][j][0] == dp[i][j][1]){
                    ans++;
                }
            }
        }
        return ans;
    }
};