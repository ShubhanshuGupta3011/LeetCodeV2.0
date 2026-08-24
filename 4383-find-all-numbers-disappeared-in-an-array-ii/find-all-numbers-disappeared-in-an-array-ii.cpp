class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        vector<int> arr(1+upper,1);
        arr[0] = 0;
        for(auto it:nums){
            if(it > upper) continue;
            arr[it]=0;
        }
        for(int i=1;i<=upper;i++){
            if(arr[i] == 0) continue;
            arr[i] = 1+arr[i-1];
        }
        vector<vector<int>> ans;
        for(int i=upper;i>=lower;i--){
            if(arr[i]==0) continue;
            ans.push_back({max(i-arr[i]+1,lower),i});
            i-=arr[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};