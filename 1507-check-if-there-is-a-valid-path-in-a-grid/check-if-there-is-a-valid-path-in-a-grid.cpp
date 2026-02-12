class Solution {
public:
    int n,m;
    bool isValid(int i,int j){
        return i>=0 && j>=0 && i<n && j<m;
    }
    vector<int> parent;
    int getparent(int u){
        if(u == parent[u]) return u;
        return parent[u] = getparent(parent[u]);
    }
    void unioned(int u,int v){
        u = getparent(u);
        v = getparent(v);
        parent[v] = u;
    }
    int getIndex(int i,int j){
        return i*m + j;
    }

    unordered_map<string,string> connection;
    unordered_map<string,vector<int>> direction;
    unordered_map<int,vector<string>> way;

    bool hasValidPath(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        for(int i=0;i<n*m;i++){
            parent.push_back(i);
        }
        connection["left"] = "right";
        connection["right"] = "left";
        connection["lower"] = "upper";
        connection["upper"] = "lower";

        direction["left"] = {0,-1};
        direction["right"] = {0,1};
        direction["lower"] = {1,0};
        direction["upper"] = {-1,0};

        way[1] = {"left","right"};
        way[2] = {"lower","upper"};
        way[3] = {"left","lower"};
        way[4] = {"right","lower"};
        way[5] = {"left","upper"};
        way[6] = {"right","upper"};
        cout<<direction["left"][0]<<endl;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int myIndex = getIndex(i,j);
                int value = grid[i][j];
                int di,dj;
                for(auto it:way[value]){
                    di = i + direction[it][0];
                    dj = j + direction[it][1];
                    if(isValid(di,dj)){
                        int neighour = getIndex(di,dj);
                        int thisValue = grid[di][dj];
                        for(auto itt:way[thisValue]){
                            if(connection[it] == itt){
                                unioned(myIndex,neighour);
                            }
                        }
                    }
                }
            }
        }

        return getparent(0) == getparent(getIndex(n-1,m-1));
    }

};
