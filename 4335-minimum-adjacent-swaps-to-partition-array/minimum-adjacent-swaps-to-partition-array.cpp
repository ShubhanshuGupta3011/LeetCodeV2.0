class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> ft;
    void update(int node){
        while(node < ft.size()){
            ft[node]++;
            node += (node & -node);
        }
    }
    int getSum(int node){
        return node ? ft[node] + getSum(node & (node-1)): 0;
    }
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
        int n = nums.size();
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            if(nums[i] < a){
                arr.push_back({0,i});
            }else if(nums[i] > b){
                arr.push_back({2,i});
            }else{
                arr.push_back({1,i});
            }
        }
        ft.resize(n+1,0);
        sort(arr.begin(),arr.end());
        long long ans = 0;
        for(int i=0;i<n;i++){
            update(1+arr[i][1]);
            ans += (i - getSum(arr[i][1]));
        }

        return ans % mod;
    }
};