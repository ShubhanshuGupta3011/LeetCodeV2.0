class Solution {
public:
    int mod=1e9+7;
    vector<int> ft;
    void update(int node){
        while(node<ft.size()){
            ft[node]++;
            node += (node & (-node));
        }
    }
    int getSum(int node){
        int ans=0;
        while(node){
            ans+=ft[node];
            node -= (node & (-node));
        }
        return ans;
    }
    int createSortedArray(vector<int>& nums) {
        int maxi=0;
        for(auto it:nums){
            maxi=max(maxi,it);
        }
        ft.resize(maxi+1,0);
        long long ans=0;
        for(int i=0;i<nums.size();i++){
            int node = nums[i];
            update(node);
            int small = getSum(node-1);
            int freq = getSum(node)-small;
            int big = i+1-freq-small;
            ans += min(small,big);
        }
        return ans%mod;
    }
};