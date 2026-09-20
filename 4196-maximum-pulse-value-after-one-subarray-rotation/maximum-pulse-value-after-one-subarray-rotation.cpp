class Solution {
public:
    long long helper(vector<int>& arr){
        long long ans = 0;
        long long part = 0;
        for(auto it:arr){
            cout<<it<<",";
        }cout<<endl;
        for(auto it:arr){
            part += it;
            ans = min(ans,part);
            if(part>0){
                part=0;
            }
        }
        cout<<"ans = "<<ans<<endl;
        return ans;
    }
    long long maxValue(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = (i&1 ? -1 : 1) * nums[i];
        }
        long long total = 0;
        for(auto it:nums){
            total += it;
        }
        vector<int> arr1,arr2;
        for(int i=1;i<n;i+=2){
            arr1.push_back(nums[i] + nums[i-1]);
        }
        for(int i=2;i<n;i+=2){
            arr2.push_back(nums[i] + nums[i-1]);
        }
        long long extra = min(helper(arr1),helper(arr2));
        // cout<<"total = "<<total<<" extra = "<<extra<<endl;
        return total - 2 * extra;
    }
};