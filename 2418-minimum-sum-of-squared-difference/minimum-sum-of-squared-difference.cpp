class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        /*
        1,4,10,12
        5,8,6,9

        4 4 4 3
        */
        int n = nums1.size();
        int k = k1+k2;
        map<int,int> mp;
        for(int i=0;i<n;i++){
            int key = -abs(nums1[i]-nums2[i]);
            mp[key]++;
        }
        while(true){
            if(k==0) break;
            for(auto it:mp){
                int key = it.first; 
                int freq = it.second;
                if(key == 0) return 0;
                if(freq >= k){
                    mp[key] = freq-k;
                    mp[1+key] += k;
                    k = 0;
                }else{
                    mp[1+key] += freq;
                    k -= freq;
                    mp.erase(key);
                }
                break;
            }
        }
        long long ans = 0;
        for(auto it:mp){
            long long key = it.first;
            long long freq = it.second;
            ans += freq * (key * key);
        }
        return ans;
    }
};