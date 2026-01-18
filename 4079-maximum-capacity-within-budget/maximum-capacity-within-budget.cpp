class Solution {
public:
    int mySearching(vector<vector<int>>& arr,int target,int low,int high){
        /*
        
        */
        if(arr[0][0]>=target) return -1;
        // int low=0,high=arr.size()-1;
        int ans=-1;
        while(low<=high){
            int mid=(low+high)/2;
            if(arr[mid][0] >= target){
                high=mid-1;
            }else{
                ans=mid;
                low=mid+1;
            }
        }
        return ans;
    }
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
        int n=costs.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[costs[i]].push_back(capacity[i]);
        }
        vector<vector<int>> arr;
        for(auto it:mp){
            int key = it.first;
            sort(it.second.rbegin(),it.second.rend());
            for(auto itt:it.second){
                arr.push_back({key,itt});
            }
        }
        int currMax=0;
        for(int i=0;i<n;i++){
            currMax = max(currMax,arr[i][1]);
            arr[i].push_back(currMax);
        }
        while(arr.size()){
            if(arr.back()[0] < budget) break;
            arr.pop_back();
        }
        if(arr.size()==0) return 0;
        int ans=0;
        for(int i=arr.size()-1;i;i--){
            int target = budget - arr[i][0];
            int index = mySearching(arr,target,0,i-1);
            if(index == -1){
                ans=max(ans,arr[i][1]);
            }else{
                ans=max(ans,arr[i][1]+arr[index][2]);
            }
        }
        ans=max(ans,arr[0][1]);
        return ans;
    }
};