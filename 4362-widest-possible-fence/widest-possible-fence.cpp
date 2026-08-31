class Solution {
public:
    int maximumWidth(vector<int>& planks) {
        unordered_map<int,int> freq;
        for(auto it:planks){
            freq[it]++;
        }
        vector<pair<int,int>> temp;
        for(auto it:freq){
            temp.push_back({it.first,it.second});
        }
        for(auto it:temp){
            cout<<it.first<<","<<it.second<<endl;
        }
        unordered_map<int,int> umap;
        for(int i=0;i<temp.size();i++){
            for(int j=0;j<i;j++){
                umap[temp[i].first + temp[j].first] += min(temp[i].second,temp[j].second);
            }
        }
        for(auto it:freq){
            umap[it.first] += it.second;
            umap[2*it.first] += (it.second/2);
        }
        int ans = 1;
        for(auto it:umap){
            ans = max(ans,it.second);
        }
        return ans;
    }
};