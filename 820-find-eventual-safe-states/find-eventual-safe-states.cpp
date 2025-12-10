class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int v = graph.size();
        vector<int> indegree(v, 0);
        vector<vector<int>> adjRev(v);
        for (int i = 0; i < v; i++) {
            for (auto it : graph[i]) {
                adjRev[it].push_back(i);
                indegree[i]++;
            }
        }

        queue<int> q;
        vector<int> safenode;
        for (int i = 0; i < v; i++) {
            if (!indegree[i]) {
                q.push(i);
            }
        }

        while (q.size()) {
            int node = q.front();
            q.pop();
            safenode.push_back(node);
            for (auto it : adjRev[node]) {
                indegree[it]--;
                if (indegree[it] == 0) {
                    q.push(it);
                }
            }
        }

        sort(safenode.begin(), safenode.end());
        return safenode;
    }
};