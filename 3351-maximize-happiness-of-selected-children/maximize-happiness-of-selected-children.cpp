class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        for(auto it:happiness){
            pq.push(it);
        }
        long long ans=0;
        int count=0;
        while(pq.size() && k){
            k--;
            int top = pq.top();
            pq.pop();
            if(top<count){
                break;
            }
            ans+=(top-count);
            count++;
        }
        return ans;
    }
};