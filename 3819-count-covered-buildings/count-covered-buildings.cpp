class Solution {
public:
    int countCoveredBuildings(int n, vector<vector<int>>& buildings) {
        map<int,set<int>> xaxis,yaxis;
        for(auto it:buildings){
            int x=it[0];
            int y=it[1];
            xaxis[x].insert(y);
            yaxis[y].insert(x);
        }
        int ans=0;
        for(auto it:buildings){
            int x=it[0];
            int y=it[1];
            if(xaxis[x].size()<3) continue;
            if(yaxis[y].size()<3) continue;
            if(*xaxis[x].begin()==y || *xaxis[x].rbegin()==y) continue;
            if(*yaxis[y].begin()==x || *yaxis[y].rbegin()==x) continue;
            ans++;
        }
        return ans;
    }
};