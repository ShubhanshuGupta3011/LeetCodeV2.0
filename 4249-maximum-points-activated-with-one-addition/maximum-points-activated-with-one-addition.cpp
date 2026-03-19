class Solution {
public:
    vector<int> parent;
    int getParent(int u){
        if(u == parent[u]) return u;
        return parent[u] = getParent(parent[u]);
    }
    void unioned(int u,int v){
        u = getParent(u);
        v = getParent(v);
        parent[v] = u;
    }
    int maxActivated(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<int,vector<int>> Xaxis,Yaxis;
        for(int i=0;i<n;i++){
            Xaxis[points[i][0]].push_back(i);
            Yaxis[points[i][1]].push_back(i);
            parent.push_back(i);
        }
        for(auto it:Xaxis){
            vector<int> index = it.second;
            for(int i=1;i<index.size();i++){
                unioned(index[i],index[i-1]);
            }
        }
        for(auto it:Yaxis){
            vector<int> index = it.second;
            for(int i=1;i<index.size();i++){
                unioned(index[i],index[i-1]);
            }
        }
        unordered_map<int,int> componentSize;
        for(int i=0;i<n;i++){
            componentSize[getParent(i)]++;
        }
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(auto it:componentSize){
            minHeap.push(it.second);
            if(minHeap.size() == 3){
                minHeap.pop();
            }
        }
        int sum = 0;
        while(minHeap.size()){
            sum += minHeap.top();
            minHeap.pop();
        }
        return 1+sum;
    }
};