class Solution {
public:
    int bitwiseComplement(int n) {
        if(!n) return 1;
        if((n & (n-1)) == 0) return n-1;
        int log = log2(n);
        log++;
        int mask = pow(2,log) - 1;
        return mask ^ n;
    }
};