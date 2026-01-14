class Solution {
public:
    vector<int> ft;
    void update(int i,int diff){
        while(i<ft.size()){
            ft[i]+=diff;
            i+=(i&-i);
        }
    }
    int getSum(int i){
        if(!i) return 0;
        return ft[i]+getSum(i&(i-1));
    }
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int diff) {
        ft.resize(60002,0);
        int n=nums1.size();
        long long ans=0;
        vector<int> arr(n);
        for(int i=0;i<n;i++){
            arr[i]=nums1[i]-nums2[i]+30001;
            int search = arr[i]+diff;
            ans += getSum(search);
            update(arr[i],1);
        }
        return ans;
    }
};