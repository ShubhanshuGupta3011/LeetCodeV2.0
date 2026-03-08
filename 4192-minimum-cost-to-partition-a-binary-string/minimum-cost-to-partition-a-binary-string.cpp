class Solution {
public:
    vector<long long> preSum;
    long long subArraySum(int l,int r){
        return preSum[r] - (l?preSum[l-1]:0);
    }
    long long helper(int low,int high,int encCost, int flatCost){
        int size = high-low+1;
        long long cost;
        int X = subArraySum(low,high);
        if(X==0){
            cost = flatCost;
        }else{
            cost = 1ll * size * X * encCost;
        }
        if(size%2) return cost;
        int mid = (low+high)/2;
        long long spilt = helper(low,mid,encCost,flatCost) + helper(mid+1,high,encCost,flatCost);
        return min(cost,spilt);
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        preSum.resize(n);
        preSum[0] = s[0]-'0';
        for(int i=1;i<n;i++){
            preSum[i] = preSum[i-1] + (s[i]-'0');
        }
        return helper(0,n-1,encCost,flatCost);
    }
};