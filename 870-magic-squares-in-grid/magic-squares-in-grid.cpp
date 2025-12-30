class Solution {
public:
    int checkMagic(vector<vector<int>> grid){
        set<int> st;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(grid[i][j]==0 || grid[i][j]>=10) return 0;
                st.insert(grid[i][j]);
            }
        }
        if(st.size()!=9) return 0;
        int sum=grid[0][0]+grid[0][1]+grid[0][2];
        if(sum!=15) return 0;
        sum=grid[1][0]+grid[1][1]+grid[1][2];
        if(sum!=15) return 0;
        sum=grid[2][0]+grid[2][1]+grid[2][2];
        if(sum!=15) return 0;
        sum=grid[0][0]+grid[1][0]+grid[2][0];
        if(sum!=15) return 0;
        sum=grid[0][1]+grid[1][1]+grid[2][1];
        if(sum!=15) return 0;
        sum=grid[0][2]+grid[1][2]+grid[2][2];
        if(sum!=15) return 0;
        sum=grid[0][0]+grid[1][1]+grid[2][2];
        if(sum!=15) return 0;
        sum=grid[0][2]+grid[1][1]+grid[2][0];
        if(sum!=15) return 0;
        return 1;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0;
        int n=grid.size();
        int m=grid[0].size();
        for(int i=2;i<n;i++){
            for(int j=2;j<m;j++){
                vector<vector<int>> arr = {
                    {grid[i-2][j-2],grid[i-2][j-1],grid[i-2][j]},
                    {grid[i-1][j-2],grid[i-1][j-1],grid[i-1][j]},
                    {grid[i][j-2],grid[i][j-1],grid[i][j]}
                };
                ans += checkMagic(arr);
            }
        }
        return ans;
    }
};