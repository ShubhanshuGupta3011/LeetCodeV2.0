class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        unordered_map<int,int> umap;
        for(auto it:items){
            umap[it[0]] = max(umap[it[0]],it[1]);
        }
        vector<vector<int>> arr;
        for(auto it:umap){
            arr.push_back({it.first,it.second});
        }
        arr.push_back({0,0});
        arr.push_back({INT_MAX,0});
        sort(arr.begin(),arr.end());
        vector<vector<int>> query;
        for(int i=0;i<queries.size();i++){
            query.push_back({queries[i],i});
        }
        sort(query.begin(),query.end());
        vector<int> ans(query.size());
        for(int i=1;i<arr.size();i++){
            arr[i][1] = max(arr[i][1],arr[i-1][1]);
        }
        int j = 0;
        for(int i=0;i<query.size();i++){
            while(arr[j][0] <= query[i][0]){
                j++;
            }
            ans[query[i][1]] = (arr[j-1][1]);
        }
        return ans;
    }
};