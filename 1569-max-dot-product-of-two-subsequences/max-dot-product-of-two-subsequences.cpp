class Solution {
public:
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2,vector<vector<int>>& dp){
        if(i>=nums1.size() || j>=nums2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int case1 = nums1[i]*nums2[j] + solve(i+1,j+1,nums1,nums2,dp);
        int case2 = solve(i+1,j+1,nums1,nums2,dp);
        int case3 = solve(i+1,j,nums1,nums2,dp);
        int case4 = solve(i,j+1,nums1,nums2,dp);
        return dp[i][j] = max({case1,case2,case3,case4});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        int ans = solve(0,0,nums1,nums2,dp);
        if(!ans){
            int countZero = 0;
            for(auto it:nums1){
                if(!it) countZero++;
            }
            if(countZero) return 0;
            countZero=0;
            for(auto it:nums2){
                if(!it) countZero++;
            }
            if(countZero) return 0;
            sort(nums1.begin(),nums1.end());
            sort(nums2.begin(),nums2.end());
            return max(nums1[0]*nums2[m-1],nums1[n-1]*nums2[0]);
        }
        return ans;
    }
};