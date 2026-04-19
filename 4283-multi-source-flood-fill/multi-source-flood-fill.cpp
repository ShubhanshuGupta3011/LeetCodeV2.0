class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> ans(n,vector<int>(m,0));
        vector<vector<int>> visTime(n,vector<int>(m,1e9));
        int x = sources.size();
        for(int i=0;i<x;i++){
            swap(sources[i][0],sources[i][2]);
        }
        sort(sources.rbegin(),sources.rend());
        for(int i=0;i<x;i++){
            swap(sources[i][0],sources[i][2]);
        }
        queue<vector<int>> q;
        for(auto it:sources){
            q.push(it);
        }
        int timer = 0;
        while(q.size()){
            int size = q.size();
            while(size--){
                auto top = q.front();
                q.pop();
                int i = top[0];
                int j = top[1];
                if(i<0 || j<0 || i>=n || j>=m) continue;
                int value = top[2];
                if(visTime[i][j] <= timer) continue;
                visTime[i][j] = timer;
                ans[i][j] = value;
                q.push({i,j+1,value});
                q.push({i,j-1,value});
                q.push({i+1,j,value});
                q.push({i-1,j,value});
            }
            timer++;
        }
        return ans;
    }
};