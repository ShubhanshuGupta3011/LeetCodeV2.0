class Solution {
public:
    int mod = 12345;
    int multi(int a,int b){
        return (1ll * a * b) % mod;
    }
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int product = 1;
        vector<vector<int>> ans(n,vector<int>(m,1));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans[i][j] = product;
                product = multi(product,grid[i][j]);
            }
        }
        product = 1;
        for(int i=n-1;i>=0;i--){
            for(int j=m-1;j>=0;j--){
                ans[i][j] = multi(ans[i][j],product);
                product = multi(product,grid[i][j]);
            }
        }
        return ans;
    }
};