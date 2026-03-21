class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int start = x;
        int end = start + k - 1;
        for(int j=y;j<y+k;j++){
            int s = start;
            int e = end;
            while(s<=e){
                swap(grid[s][j],grid[e][j]);
                s++;
                e--;
            }
        }
        return grid;
    }
};