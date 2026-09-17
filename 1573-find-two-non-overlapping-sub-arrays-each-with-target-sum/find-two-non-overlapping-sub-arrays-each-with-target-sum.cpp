class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<long long,int> umap1;
        long long key = 0;
        vector<int> ans1(n,INT_MAX);
        int len = INT_MAX;
        umap1[0] = -1;
        for(int i=0;i<n;i++){
            key += arr[i];
            if(umap1.count(key-target)){
                len = min(len,i-umap1[key-target]);
            }
            umap1[key] = i;
            ans1[i] = len;
        }
        len = INT_MAX;
        unordered_map<long long,int> umap2;
        umap2[0] = n;
        key = 0;
        vector<int> ans2(n,INT_MAX);
        for(int i=n-1;i>=0;i--){
            ans2[i] = len;
            key += arr[i];
            if(umap2.count(key-target)){
                len = min(len,umap2[key-target]-i);
            }
            umap2[key] = i;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            if(ans1[i]==INT_MAX || ans2[i]==INT_MAX) continue;
            ans = min(ans,ans1[i]+ans2[i]);
        }
        // for(auto it:ans1){
        //     cout<<it<<",";
        // }cout<<endl;
        
        // for(auto it:ans2){
        //     cout<<it<<",";
        // }cout<<endl;
        return ans==INT_MAX?-1:ans;
    }
};