class Solution {
public:
    vector<vector<vector<int>>> nextQueries;
    int searching(vector<vector<int>>& forSearch,int value){
        if(forSearch.empty()) return -1;
        int low = 0;
        int high = forSearch.size()-1;
        int ans=-1;
        while(low<=high){
            int mid = (low+high)/2;
            if(forSearch[mid][0] > value){
                ans = mid;
                low = mid+1;
            }else{
                high = mid-1;
            }
        }
        if(ans==-1) return -1;
        return forSearch[ans][1];
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n = heights.size();
        int q = queries.size();
        vector<int> ans(q,-1);
        vector<vector<int>> forSearch; 
        nextQueries.resize(n,{});
        for(int i=0;i<q;i++){
            int a = queries[i][0];
            int b = queries[i][1];
            if(a>b){
                swap(a,b);
            }
            if(a==b || heights[a] < heights[b]){
                ans[i]=b;
                continue;
            }
            nextQueries[b].push_back({heights[a],i});
        }
        for(int i=n-1;i>=0;i--){
            for(auto it:nextQueries[i]){
                int qIndex = it[1];
                int res = searching(forSearch,it[0]);
                ans[qIndex] = res;
            }
            int currHeight = heights[i];
            while(forSearch.size() && forSearch.back()[0] <= currHeight){
                forSearch.pop_back();
            }
            forSearch.push_back({currHeight,i});
        }
        for(auto it:forSearch){
            cout<<it[0]<<","<<it[1]<<endl;
        }
        return ans;
    }
};