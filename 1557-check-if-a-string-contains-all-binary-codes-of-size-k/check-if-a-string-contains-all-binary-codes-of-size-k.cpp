class Solution {
public:
    void helper(int k,string part,unordered_set<string>& look_up2){
        if(k==0){
            look_up2.insert(part);
            return ;
        }
        helper(k-1,"1"+part,look_up2);
        helper(k-1,"0"+part,look_up2);
    }
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        int number_of_substring = n - k + 1;
        int totalCase = pow(2,k);
        if(number_of_substring < totalCase) return 0;
        unordered_set<string> look_up;
        string key = "";
        while(key.size() != k){
            key = s.back() + key;
            s.pop_back();
        }
        look_up.insert(key);
        while(s.size()){
            key = s.back() + key;
            s.pop_back();
            key.pop_back();
            look_up.insert(key);
        }
        unordered_set<string> look_up2;
        helper(k,"",look_up2);
        return look_up == look_up2;
    }
};