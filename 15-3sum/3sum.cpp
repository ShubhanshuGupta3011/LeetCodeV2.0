class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            if(i && nums[i]==nums[i-1]) continue;
            if(nums[i]>0) continue;
            int target = -nums[i];
            int start = i+1;
            int end = n-1;
            while(start < end){
                if(nums[start] + nums[end] == target){
                    ans.push_back({nums[i],nums[start],nums[end]});
                    while(start < n-1 && nums[start] == nums[start+1]){
                        start++;
                    }
                    while(end && nums[end]==nums[end-1]){
                        end--;
                    }
                    start++;
                    end--;
                }else if(nums[start] + nums[end] > target){
                    end--;
                }else{
                    start++;
                }
            }
        }
        return ans;
    }
};