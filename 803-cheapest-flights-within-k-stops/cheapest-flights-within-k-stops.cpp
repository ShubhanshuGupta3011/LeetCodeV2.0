class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(auto it:flights){
            graph[it[0]].push_back({it[1],it[2]});
        }

        vector<int> dis(n,1e9);
        queue<pair<int,pair<int,int>>> q;
        q.push({0,{src,0}});

        while(q.size()){
            auto it = q.front();
            q.pop();
            int step = it.first;
            int currNode = it.second.first;
            int currDis = it.second.second;
            if(step > k){
                if(currNode == dst) dis[dst] = min(dis[dst] , currDis);
                continue;
            }

            for(auto x:graph[currNode]){
                int nextCurr = x.first;
                int dist = x.second;
                if(currDis + dist < dis[nextCurr]){
                    dis[nextCurr] = currDis + dist;
                    q.push({1+step,{nextCurr,dis[nextCurr]}});
                }
            }
        }

        return dis[dst]==1e9?-1:dis[dst];
    }
};