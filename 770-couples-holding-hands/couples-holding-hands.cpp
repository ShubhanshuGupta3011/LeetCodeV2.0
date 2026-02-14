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
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        int half = n/2;
        for(int i=0;i<n;i++){
            parent.push_back(i);
        }
        for(int i=0;i<n;i+=2){
            unioned(i,i+1);
        }
        for(int i=0;i<n;i+=2){
            unioned(row[i],row[i+1]);
        }
        unordered_set<int> st;
        for(int i=0;i<n;i++){
            st.insert(getParent(i));
        }
        return half - st.size();
    }
};