class Solution {
public:
    int MOD = 1e9 + 7;
    int multi(int a,int b){
        return (1ll * a* b) %MOD;
    }
    int maximumProduct(vector<int>& nums, int k) {
        priority_queue<int,vector<int>,greater<int>> pq;
        for(auto it:nums){
            pq.push(it);
        }
        while(k--){
            auto it = pq.top();
            pq.pop();
            pq.push(1+it);
        }
        int ans=1;
        while(pq.size()){
            ans = multi(ans,pq.top());
            pq.pop();
        }
        return ans;
    }
};