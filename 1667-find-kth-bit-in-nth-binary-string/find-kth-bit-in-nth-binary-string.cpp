class Solution {
public:
    bool helper(int n,int k){
        if(n==1) return 0;
        int total = pow(2,n)-1;
        int mid = (1+total)/2;
        if(mid == k) return 1;
        if(mid > k) return helper(n-1,k);
        int newK = 2*mid - k;
        return !helper(n-1,newK);
    }
    char findKthBit(int n, int k) {
        bool ans = helper(n,k);
        return ans?'1':'0';
    }
};