class Solution {
public:
    int maxFrequency(vector<int>& arr, int k) {
    sort(arr.begin(),arr.end());
    int ans=0;
    int left=0;
    int right=0;
    long long preSum=0;
    long long targetSum=0;
    while(right<arr.size()){
        int window = right-left; // number of element small than me
        targetSum = 1ll * window * arr[right];
        if(targetSum - preSum > k ){
            preSum -= arr[left];
            left++;
        }else{
            ans=max(ans,1+window);
            preSum += arr[right];
            right++;
        }
    }
    return ans;
    }
};