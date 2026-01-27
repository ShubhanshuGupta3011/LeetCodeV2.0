class Solution {
public:
    vector<vector<pair<int,int>>> graph;
    
    int dijkstra(int n){
        vector<bool> vis(n, false);
        vector<int> dist(n, 1e9);
        
        priority_queue<pair<int,int> > pq;
        pq.push({0, 0});
        dist[0] = 0;
        while(!pq.empty()){
            int u = pq.top().second;
            pq.pop();
            if(vis[u]) continue;
            vis[u] = true;
            for(auto [v, w] : graph[u]){
                if(dist[u] + w < dist[v]){
                    dist[v] = dist[u] + w;
                    pq.push({-dist[v], v});
                }
            }
        }
        if(dist[n - 1] == 1e9) return -1;
        return dist[n - 1];
    }
    
    int minCost(int n, vector<vector<int>>& edgraphes) {
        graph.resize(n);
        for(auto edgraphe : edgraphes){
            int u = edgraphe[0];
            int v = edgraphe[1];
            int w = edgraphe[2];
            graph[u].push_back({v, w});
            graph[v].push_back({u, 2 * w});
        }
        return dijkstra(n);
    }
};