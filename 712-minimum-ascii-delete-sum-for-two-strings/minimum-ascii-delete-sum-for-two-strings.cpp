class Solution {
public:
    int solve(int i,int j,vector<int>& arr1,vector<int>& arr2,vector<vector<int>>& dp){
        if(i>=arr1.size() && j>=arr2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int case1=1e9;
        int case2=1e9;
        int case3=1e9;
        if(i<arr1.size() && j<arr2.size() && arr1[i] == arr2[j]){
            case1 = solve(i+1,j+1,arr1,arr2,dp);
        }
        if(i<arr1.size()){
            case2 = arr1[i] + solve(i+1,j,arr1,arr2,dp);
        }
        if(j<arr2.size()){
            case3 = arr2[j] + solve(i,j+1,arr1,arr2,dp);
        }
        return dp[i][j] = min({case1,case2,case3});
    }
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.size()+1,vector<int>(s2.size()+1,-1));
        vector<int> arr1,arr2;
        for(auto it:s1){
            arr1.push_back(it-'a'+97);
        }
        for(auto it:s2){
            arr2.push_back(it-'a'+97);
        }
        return solve(0,0,arr1,arr2,dp);
    }
};