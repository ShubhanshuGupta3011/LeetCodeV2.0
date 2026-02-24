class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        using T = pair<int,pair<int,int>>;
        priority_queue<T> pq;
        int n = nums1.size();
        int m = nums2.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                T it = {nums1[i]+nums2[j],{nums1[i],nums2[j]}};
                if(pq.size() == k){
                    T top = pq.top();
                    if(top.first <= it.first){
                        break;
                    }
                    pq.pop();
                }
                pq.push(it);
            }
        }
        vector<vector<int>> ans;
        while(pq.size()){
            T it = pq.top();
            pq.pop();
            ans.push_back({it.second.first,it.second.second});
        }
        return ans;
    }
};