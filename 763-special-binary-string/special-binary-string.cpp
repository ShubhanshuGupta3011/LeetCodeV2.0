class Solution {
public:
    string makeLargestSpecial(string s) {
        int i = 0;
        int one = 0;
        int zero = 0;
        int n = s.size();
        vector<string> res;
        for (int j = 0; j < n; j++) {
            s[j]=='1' ? one++ : zero++ ;
            if (one == zero) {
                res.push_back(
                    '1' + makeLargestSpecial(s.substr(i + 1, j - i - 1)) + '0');
                i = j + 1;
            }
        }
        sort(res.rbegin(), res.rend());
        string ans;
        for (auto str : res) {
            ans += str;
        }
        return ans;
    }
};