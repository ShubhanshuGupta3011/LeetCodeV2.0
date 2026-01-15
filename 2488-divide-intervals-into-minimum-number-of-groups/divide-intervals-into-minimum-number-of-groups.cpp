class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        map<int,int> mp;
        for(auto it:intervals){
            mp[it[0]]++;
            mp[it[1]+1]--;
        }
        int sum=0;
        int ans=0;
        for(auto it:mp){
            int key = it.first;
            int value = it.second;
            sum += value;
            mp[key] = sum;
            ans=max(ans,sum);
        }
        return ans;
    }
};