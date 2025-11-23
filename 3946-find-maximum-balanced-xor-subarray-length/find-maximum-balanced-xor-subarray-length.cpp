class Solution {
public:
    int helper(vector<int>& nums,vector<vector<int>>& arr){
        int n=nums.size();
        if(n<2) return 0;
        cout<<endl;
        unordered_map<int,int> mp;
        int ans=0;
        if(nums[0]==-1){
            mp[0]=-1;
        }
        for(int i=0;i<n;i++){
            if(nums[i]==-1) continue;
            int index=nums[i];
            int key = arr[index][1] - arr[index][0];
            if(mp.find(key) != mp.end()){
                ans=max(ans,index-mp[key]);
            }else{
                mp[key]=index;
            }
        }
        cout<<endl;
        return ans;
    }
    int maxBalancedSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,vector<int>> mp;
        vector<vector<int>> arr(n,vector<int>(2));
        int totalXor = 0;
        mp[totalXor].push_back(-1);
        for(int i=0;i<n;i++){
            totalXor ^= nums[i];
            mp[totalXor].push_back(i);
            if(nums[i]%2){
                arr[i][1]=1;
                arr[i][0]=0;
            }else{
                arr[i][0]=1;
                arr[i][1]=0;
            }
            if(i){
                arr[i][0] += arr[i-1][0];
                arr[i][1] += arr[i-1][1];
            }
        }
        int ans=0;
        for(auto it:mp){
            ans=max(ans,helper(it.second,arr));
        }
        return ans;
    }
};