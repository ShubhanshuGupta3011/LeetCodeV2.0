class Solution {
public:
    bool possibleBipartition(int N, vector<vector<int>>& rivalry) {
        if(N==0 || N==1) return true;
        if(rivalry.empty()) return true;
        vector<vector<int>> graph(N);
        for(auto it:rivalry){
            int u = it[0]-1;
            int v = it[1]-1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        int red=1;
        int black=-1;
        int colorLess=0;
        
        vector<int> color(N,colorLess);
        queue<int> q;
        for(int i=0;i<N;i++){
            if(color[i] != colorLess) continue;
            color[i] = red;
            q.push(i);
            while(!q.empty()){
                int node = q.front();
                q.pop();
                for(auto it:graph[node]){
                    if(color[it] == color[node]) return false;
                    if(color[it] + color[node] == 0) continue;
                    color[it] = -color[node];
                    q.push(it);
                }
            }
        }
        return true;
    }
};