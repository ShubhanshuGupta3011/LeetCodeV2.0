class Solution {
public:
    vector<int> ft;
    void update(int node){
        while(node<ft.size()){
            ft[node]++;
            node += (node&(-node));
        }
    }
    int getsum(int node){
        int ans=0;
        while(node){
            ans+=ft[node];
            node -= (node&(-node));
        }
        return ans;
    }
    vector<int> countSmaller(vector<int>& nums) {
        int mini=INT_MAX,maxi=0;
        for(auto it:nums){
            mini=min(mini,it);
        }
        for(int i=0;i<nums.size();i++){
            nums[i]=nums[i]+1-mini;
            maxi=max(maxi,nums[i]);
        }
        ft.resize(maxi+1,0);
        vector<int> ans;
        reverse(nums.begin(),nums.end());
        for(auto node:nums){
            update(node);
            ans.push_back(getsum(node-1));
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};