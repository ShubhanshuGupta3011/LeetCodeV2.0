class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        vector<int> arr = {0,0,0};
        for(auto it:stones){
            arr[it%3]++;
        }
        if(arr[0] % 2){
            int gap = abs(arr[1]-arr[2]);
            return gap >= 3;
        }
        return arr[1] && arr[2];
    }
};