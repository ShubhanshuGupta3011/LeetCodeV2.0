class Solution {
public:
    int sumOfDigit(int n){
        return n ? (n%10 + sumOfDigit(n/10)) : 0;
    }
    int helper(vector<int>& arr){
        if(arr.size() < 2) return -1;
        sort(arr.begin(),arr.end());
        int ans = arr.back();
        arr.pop_back();
        ans += arr.back();
        return ans;
    }
    int maximumSum(vector<int>& nums) {
        unordered_map<int,vector<int>> umap;
        for(auto it:nums){
            umap[sumOfDigit(it)].push_back(it);
        }
        int ans = -1;
        for(auto it:umap){
            ans = max(ans,helper(it.second));
        }
        return ans;
    }
};