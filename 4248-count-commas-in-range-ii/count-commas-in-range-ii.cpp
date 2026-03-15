class Solution {
public:
    long long helper(long long n,long long low){
        if(n<low) return 0;
        return (n-low+1) + helper(n,1000 * low);
    }
    long long countCommas(long long n) {
        return helper(n,1000);
    }
};