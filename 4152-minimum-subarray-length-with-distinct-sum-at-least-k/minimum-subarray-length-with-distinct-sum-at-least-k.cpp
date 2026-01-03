class Solution {
public:
    int minLength(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0;
        int j=0;
        long long sum=0;
        int ans=1e9;
        multiset<int> mst;
        while(i<n){
            if(mst.find(nums[i])!=mst.end()){
                mst.insert(nums[i]);
            }else{
                mst.insert(nums[i]);
                sum+=nums[i];
                while(sum>=k && j<=i){
                    ans=min(ans,i-j+1);
                    int value=nums[j];
                    if(mst.count(value)==1){
                        mst.erase(value);
                        sum-=value;
                    }else{
                        mst.erase(mst.find(value));
                    }
                    j++;
                }
            }
            i++;
        }
        return ans==1e9?-1:ans;
    }
};