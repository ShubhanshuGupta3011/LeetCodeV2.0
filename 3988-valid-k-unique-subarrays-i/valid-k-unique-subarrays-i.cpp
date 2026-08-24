class Solution {
public:
    vector<int> helper(vector<int>& nums, int k){
        int n = nums.size();
        int i=0,j=0;
        unordered_map<int,int> freq;
        vector<int> ans(n,0);
        while(j<n){
            freq[nums[j]]++;
            while(freq.size() > k){
                freq[nums[i]]--;
                if(freq[nums[i]] == 0){
                    freq.erase(nums[i]);
                }
                i++;
            }
            if(freq.size() == k){
                ans[j] = i;
            }
            j++;
        }
        return ans;
    }
    vector<bool> validSubarrays(vector<int>& nums, int k, vector<vector<int>>& queries) {
        int n = nums.size();
        int q = queries.size();
        vector<int> preXor(n,0);
        preXor[0] = nums[0];
        for(int i=1;i<n;i++){
            preXor[i] = preXor[i-1]^nums[i];
        }
        vector<bool> ans(q,false);
        vector<vector<int>> validQueries;
        for(int i=0;i<q;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int gap = r - l + 1;

            // always inValid queries
            if(gap & 1) continue;
            if(gap < 2*k) continue;
            if(preXor[r] ^ preXor[l] ^ nums[l]) continue;

            // inserting Valid queries
            validQueries.push_back({l,r,i});
        }
        vector<int> arr1 = helper(nums,k);
        vector<int> arr2 = helper(nums,k-1);
        if(k==1){
            for(auto it:validQueries){
                int l = it[0];
                int r = it[1];
                int index = it[2];
                if(l >= arr1[r]){
                    ans[index] = true;
                }
            }
        }else{
            for(auto it:validQueries){
                int l = it[0];
                int r = it[1];
                int index = it[2];
                int start = arr2[r];
                int end = arr1[r];
                if(end<=l && l<=start){
                    ans[index] = true; 
                }
            }
        }
        return ans;
    }
};