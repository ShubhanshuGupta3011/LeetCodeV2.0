class Solution {
public:
    int helper(vector<int>& nums){
        int n = nums.size();
        vector<int> pre(n);
        vector<int> post(n);
        pre[0] = nums[0];
        post[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            pre[i] = gcd(nums[i],pre[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            post[i] = gcd(nums[i],post[i+1]);
        }
        int ans = 0;
        for(int i=1;i<n;i++){
            ans += (post[i] == pre[i-1]);
        }
        return ans;
    }
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n);
        vector<int> post(n);
        pre[0] = nums[0];
        post[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            pre[i] = gcd(nums[i],pre[i-1]);
        }
        for(int i=n-2;i>=0;i--){
            post[i] = gcd(nums[i],post[i+1]);
        }
        vector<int> bad_index;
        bad_index.push_back(-1);
        bad_index.push_back(0);
        for(int i=1;i<n;i++){
            if(pre[i] != pre[i-1]){
                bad_index.push_back(i);
            }else if(post[i] != post[i-1]){
                bad_index.push_back(i);
            }else{
                // continue;
            }
        }
        bad_index.push_back(n-1);
        int ans = 0;
        for(auto bad:bad_index){
            vector<int> arr;
            for(int i=0;i<n;i++){
                if(i==bad) continue;
                arr.push_back(nums[i]);
            }
            ans = max(ans,helper(arr));
        }
        return ans;
    }
};