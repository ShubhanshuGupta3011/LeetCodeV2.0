class Solution {
public:
    vector<int> fact = {1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880};
    
    string getPermutation(int n, int k) {
        string res = "";
        vector<char> chars(n);
        int pos;
        k--; 
        for (int i = 1; i <= n;) chars[i++ - 1] = '0' + i;
        while (n) {
            pos = k / fact[--n];
            res += chars[pos];
            chars.erase(begin(chars) + pos);
            k %= fact[n];
        }
        return res;
    }
};