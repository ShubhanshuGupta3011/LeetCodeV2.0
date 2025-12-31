class Solution {
public:
    int n,m;
    int isValid(int i,int j){
        return i>=0 && i<n && j>=0 && j<m;
    }
    int row[4] = {1,-1,0,0};
    int col[4] = {0,0,1,-1};
    bool solve(int i,int j,vector<vector<int>>& arr){
        if(i==(n-1)) return true;
        arr[i][j]=1;
        bool ans=0;
        for(int k=0;k<4;k++){
            int ii = i+row[k];
            int jj = j+col[k];
            if(isValid(ii,jj) && !arr[ii][jj]){
                ans |= solve(ii,jj,arr);
            }
        }
        return ans;
    }
    bool helper(int size,vector<vector<int>>& cells){
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int k=0;k<size;k++){
            int i=cells[k][0]-1;
            int j=cells[k][1]-1;
            arr[i][j]=1;
        }
        bool ans=0;
        for(int j=0;j<m;j++){
            if(arr[0][j]==0){
                ans = ans || solve(0,j,arr);
            }
        }
        return ans;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        n=row;
        m=col;
        int ans=0;
        int low=1;
        int high=cells.size();
        while(low<=high){
            int mid=(low+high)/2;
            bool canReachDown = helper(mid,cells);
            if(canReachDown){
                ans=mid;
                low=mid+1;
            }else{
                high=mid-1;
            }
        }
        return ans;
    }
};