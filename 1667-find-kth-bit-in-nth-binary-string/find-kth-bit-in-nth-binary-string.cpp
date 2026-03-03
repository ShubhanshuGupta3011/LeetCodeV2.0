class Solution {
public:
    bool helper(int n,int k){
        if(n==1) return 0;
        int total = pow(2,n)-1;
        int mid = (1+total)/2;
        if(mid == k) return 1;
        // answer is on left side 
        if(mid > k) return helper(n-1,k);
        // answer is on right side
        return !helper(n-1, 2*mid - k);
    }
    char findKthBit(int n, int k) {
        bool ans = helper(n,k);
        return ans?'1':'0';
    }
};