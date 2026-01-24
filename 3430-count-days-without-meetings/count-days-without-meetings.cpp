class Solution {
public:
    int countDays(int days, vector<vector<int>>& meetings) {
        map<int,int> mp;
        for(auto it:meetings){
            mp[it[0]]++;
            mp[1+it[1]]--;
        }
        int ans=0;
        int start=1;
        int counter=0;
        vector<vector<int>> arr;
        arr.push_back({1,0});
        for(auto it:mp){
            int key = it.first;
            int value = it.second;
            arr.push_back({key,value});
        }
        for(int i=1;i<arr.size();i++){
            arr[i][1] += arr[i-1][1];
        }
        arr.push_back({1+days,0});
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i][1]) continue;
            int curr = arr[i][0];
            int next = arr[i+1][0];
            ans+=(next-curr);
        }
        return ans;
    }
};