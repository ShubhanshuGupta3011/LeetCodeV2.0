class Solution {
public:
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
        return look_up.size() == totalCase;
    }
};