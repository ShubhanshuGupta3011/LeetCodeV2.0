class Solution {
public:
    long long helper(long long n){
        if(!n) return 0;
        long long k=n/2;
        return 2*(k-helper(k));
    }
    long long lastInteger(long long n) {
        return 1+helper(n-1);
    }
};