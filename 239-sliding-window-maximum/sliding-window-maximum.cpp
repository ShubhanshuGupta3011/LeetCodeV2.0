class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        multiset<int> mst;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(mst.size() == k){
                ans.push_back(*mst.rbegin());
            }
            mst.insert(nums[i]);
            if(i>=k){
                mst.erase(mst.find(nums[i-k]));
            }
        }
        ans.push_back(*mst.rbegin());
        return ans;
    }
};