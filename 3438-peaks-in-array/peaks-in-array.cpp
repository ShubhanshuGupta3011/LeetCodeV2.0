class Solution {
public:
    vector<int> ft;
    void update(int node,int diff){
        while(node < ft.size()){
            ft[node]+=diff;
            node += (node & -node);
        }
    }
    int getSum(int node){
        int ans=0;
        while(node){
            ans+=ft[node];
            node -= (node & -node);
        }
        return ans;
    }
    void checker(int index,vector<int>& nums){
        if(index <= 0 || index >= nums.size()-1) return ;
        int isPeak = getSum(index+1) - getSum(index);
        int isNowPeak = nums[index] > nums[index-1] && nums[index]>nums[index+1];
        if(isPeak){
            if(!isNowPeak) update(index+1,-1);
        }else{
            if(isNowPeak) update(index+1,1);
        }
    }
    vector<int> countOfPeaks(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        ft.resize(n+1,0);
        for(int i=1;i<n-1;i++){
            if(nums[i] > nums[i-1] && nums[i] > nums[i+1]){
                update(i+1,1);
            }
        }
        vector<int> ans;
        for(auto it:queries){
            if(it[0]==1){
                int l = it[1];
                int r = it[2];
                if(r-l+1 <= 2){
                    ans.push_back(0);
                    continue;
                }
                ans.push_back(getSum(r)-getSum(l+1));
            }else{
                int ind = it[1];
                int before = nums[ind];
                nums[ind] = it[2];
                int after = nums[ind];
                checker(ind-1,nums);
                checker(ind,nums);
                checker(ind+1,nums);
            }
        }
        return ans;
    }
};