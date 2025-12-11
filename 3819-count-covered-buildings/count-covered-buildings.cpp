class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int,vector<int>> xaxis,yaxis;
        for(auto it:buildings){
            int x=it[0];
            int y=it[1];
            xaxis[x].push_back(y);
            yaxis[y].push_back(x);
        }
        for(auto it:xaxis){
            int key=it.first;
            sort(xaxis[key].begin(),xaxis[key].end());
        }
        for(auto it:yaxis){
            int key=it.first;
            sort(yaxis[key].begin(),yaxis[key].end());
        }
        int ans=0;
        for(auto it:buildings){
            int x=it[0];
            int y=it[1];
            if(xaxis[x].size()<3) continue;
            if(yaxis[y].size()<3) continue;
            if(xaxis[x][0]==y || xaxis[x].back()==y) continue;
            if(yaxis[y][0]==x || yaxis[y].back()==x) continue;
            ans++;
        }
        return ans;
    }
};