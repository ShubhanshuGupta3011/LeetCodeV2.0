class Solution {
public:
    vector<int> smallestTrimmedNumbers(vector<string>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int m = nums[0].size();
        int q = queries.size();
        vector<int> ans(q);
        for(int i=0;i<q;i++){
            swap(queries[i][0],queries[i][1]);
            queries[i].push_back(i);
        }
        sort(queries.rbegin(),queries.rend());
        for(int i=0;i<n;i++){
            reverse(nums[i].begin(),nums[i].end());
        }
        vector<int> myIndexList(n);
        for(int i=0;i<n;i++){
            myIndexList[i]=i;
        }
        for(int j=0;j<m;){
            vector<int> storeIndex[10];
            for(auto index:myIndexList){
                int value = nums[index][j]-'0';
                storeIndex[value].push_back(index);
            }
            int ind=0;
            for(int i=0;i<10;i++){
                for(auto it:storeIndex[i]){
                    myIndexList[ind]=it;
                    ind++;
                }
            }
            j++;
            while(queries.size()){
                int trimmed = queries.back()[0];
                int pos = queries.back()[1];
                int index = queries.back()[2];
                if(j!=trimmed) break;
                ans[index] = myIndexList[pos-1];
                queries.pop_back();
            }
        }
        return ans;
    }
};