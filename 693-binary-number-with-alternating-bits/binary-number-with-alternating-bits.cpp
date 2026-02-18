class Solution {
public:
    bool hasAlternatingBits(int n) {
        int value = n ^ (n/2);
        if(value != INT_MAX) return !(value & (1+value));
        return 1;
    }
};