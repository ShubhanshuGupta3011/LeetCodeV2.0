class Solution {
public:
    vector<vector<int>> arr;
    int total;
    pair<int,int> getSizeAndMedian(int mask){
        if(!mask) return {0,0};
        int size = arr[mask].size();
        int median = arr[mask][(size-1)/2];
        return {size,median};
    }
    vector<int> merge(vector<int> a,vector<int> b){
        vector<int> ans;
        int i=0,j=0;
        while(i<a.size() && j<b.size()){
            if(a[i]<b[j]){
                ans.push_back(a[i++]);
            }else{
                ans.push_back(b[j++]);
            }
        }
        while(i<a.size()){
            ans.push_back(a[i++]);
        }
        while(j<b.size()){
            ans.push_back(b[j++]);
        }
        return ans;
    }
    long long solve(int mask,vector<long long>& dp){
        if(dp[mask]!=-1) return dp[mask];
        long long ans=1e18;
        for(int i=1;i<mask;i++){
            int previ = mask-i;
            if(previ & i) continue;
            pair<int,int> a = getSizeAndMedian(i);
            pair<int,int> b = getSizeAndMedian(previ);
            long long part = a.first + b.first + abs(a.second -b.second) + solve(i,dp) + solve(previ,dp);
            ans=min(ans,part);
        }
        return dp[mask] = ans;
    }
    long long minMergeCost(vector<vector<int>>& lists) {
        arr.push_back({});
        int n=lists.size();
        total = pow(2,n);
        vector<long long> dp(total,-1);
        for(int i=1;i<total;i++){
            int previ = i & (i-1);
            int curri = i - previ;
            arr.push_back(merge(arr[previ],lists[log2(curri)]));
        }
        for(int i=0;i<n;i++){
            dp[pow(2,i)]=0;
        }
        dp[0]=0;
        return solve(total-1,dp);
    }
};