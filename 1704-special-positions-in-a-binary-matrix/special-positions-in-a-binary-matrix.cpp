class Solution {
public:
    int helper(vector<vector<int>>& mat,int x,int y){
        int n = mat.size();
        int m = mat[0].size();
        int countRow = 0;
        int countCol = 0;
        for(int i=0;i<n;i++){
            countCol += mat[i][y];
        }
        for(int j=0;j<m;j++){
            countRow += mat[x][j];
        }
        return countRow==1 && countCol==1;
    }
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        int ans=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]){
                    ans += helper(mat,i,j);
                }
            }
        }
        return ans;
    }
};