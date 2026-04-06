class Solution {
public:
    bool judgeCircle(string moves) {
        unordered_map<char,int> mp;
        for(auto it:moves){
            mp[it]++;
        }
        return mp['R']==mp['L'] && mp['U']==mp['D'];
    }
};