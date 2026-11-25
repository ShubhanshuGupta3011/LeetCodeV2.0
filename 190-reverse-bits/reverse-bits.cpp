class Solution {
public:
    int reverseBits(int n) {
        int res = 0;

        for(int i=1;i<31;i++){
            if(n & (1<<i)){
                res += (1<<(31-i));
            }
        }

        return res;
    }
};