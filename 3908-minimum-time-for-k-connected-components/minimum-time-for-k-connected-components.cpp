class Solution {
public:
    vector<int> parent;
    int getParent(int u){
        if(u==parent[u]) return u;
        return parent[u] = getParent(parent[u]);
    }
    void unioned(int u,int v){
        u = getParent(u);
        v = getParent(v);
        parent[v] = u;
    }
    int getComponentSize(int n, vector<vector<int>>& edges, int mid){
        for(int i=0;i<n;i++){
            parent[i]=i;
        }
        for(auto it:edges){
            if(it[0] <= mid) break;
            unioned(it[1],it[2]);
        }
        unordered_set<int> component;
        for(int i=0;i<n;i++){
            component.insert(getParent(i));
        }
        return component.size();
    }
    int minTime(int n, vector<vector<int>>& edges, int k) {
        parent.resize(n);
        for(int i=0;i<edges.size();i++){
            swap(edges[i][2],edges[i][0]);
        }
        sort(edges.rbegin(),edges.rend());

        int low=0, high=edges.size() ? edges[0][0] : 1e9;
        int ans=0;
        while(low<=high){
            int mid=(low+high)/2;
            int currComponent = getComponentSize(n,edges,mid);
            if(currComponent >= k){
                ans = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
        }
        return ans;
    }
};