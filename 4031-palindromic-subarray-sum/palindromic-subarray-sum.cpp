class Solution {
public:
    vector<int> manacher(vector<int>& arr){
        int n = arr.size();
        vector<int> p(n,1);
        int l=1,r=1;
        for(int i=1;i<n;i++){
            if(l+r-i>=0){
                p[i] = max(1,min(r-i,p[l+r-i]));
            }
            while((i-p[i])>=0 && (i+p[i])<n && arr[i-p[i]]==arr[i+p[i]]){
                p[i]++;
            }
            if(i+p[i] > r){
                l = i-p[i];
                r = i+p[i];
            }
        }
        return p;
    }
    long long getSum(vector<int>& nums) {
        vector<int> arr;
        for(auto it:nums){
            arr.push_back(0);
            arr.push_back(it);
        }
        arr.push_back(0);
        vector<int> len = manacher(arr);
        vector<long long> preSum;
        preSum.push_back(0);
        for(int i=1;i<arr.size();i++){
            preSum.push_back(arr[i] + preSum[i-1]);
        }
        long long ans = 0;
        for(int i=0;i<arr.size();i++){
            int l = i - (len[i]-1);
            int e = i + (len[i]-1);
            ans = max(ans,preSum[e] - preSum[l] + arr[l]);
        }
        return ans;
    }
};