class Solution {
public:
    int isValid(int i,int j,int n,int m){
        return i>=0 && j>=0 && i<n && j<m;
    }
    vector<int> dirX = {1,-1,0,0};
    vector<int> dirY = {0,0,1,-1};
    vector<int> maxPoints(vector<vector<int>>& grid, vector<int>& queries) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<int>> vis(n,vector<int>(m,0));
        vector<vector<int>> q;
        for(int i=0;i<queries.size();i++){
            q.push_back({queries[i],i});
        }
        sort(q.rbegin(),q.rend());
        using T = pair<int,pair<int,int>> ;
        priority_queue<T,vector<T>,greater<T>> pq;
        pq.push({grid[0][0],{0,0}});
        vis[0][0]=1;
        int counter=0;
        vector<int> ans(q.size());
        while(q.size()){
            auto it=q.back();
            q.pop_back();
            int Threshold = it[0];
            int index = it[1];
            while(pq.size()){
                auto it = pq.top();
                if(it.first >= Threshold) break;
                counter++;
                pq.pop();
                int i = it.second.first;
                int j = it.second.second;
                for(int k=0;k<4;k++){
                    int ii = i+dirX[k];
                    int jj = j+dirY[k];
                    if(isValid(ii,jj,n,m) && !vis[ii][jj]){
                        vis[ii][jj]=1;
                        pq.push({grid[ii][jj],{ii,jj}});
                    }
                }
            }
            ans[index] = counter;
        }
        return ans;
    }
};