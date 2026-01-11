class Solution {
public:
    int mod = 1e9 + 7;
    vector<long long> dis;
    vector<long long> ways;
    vector<vector<vector<int>>> adj;
    int countPaths(int n, vector<vector<int>>& roads) {
        adj.resize(n, {});
        for (auto it : roads) {
            int u = it[0];
            int v = it[1];
            int time = it[2];
            adj[u].push_back({time, v});
            adj[v].push_back({time, u});
        }
        using T = pair<long long, int>;
        priority_queue<T, vector<T>, greater<T>> pq;
        dis.resize(n, 1e18);
        ways.resize(n, 0);
        dis[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        while (pq.size()) {
            auto it = pq.top();
            long long currTime = it.first;
            int node = it.second;
            pq.pop();
            for (auto child : adj[node]) {
                long long newTime = child[0];
                int nextNode = child[1];
                if (newTime + currTime < dis[nextNode]) {
                    dis[nextNode] = newTime + currTime;
                    pq.push({dis[nextNode], nextNode});
                    ways[nextNode] = ways[node];
                } else if (newTime + currTime == dis[nextNode]) {
                    ways[nextNode] = (ways[nextNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};