class Solution {
public:
    int minAllOneMultiple(int k) {
        if(k%2==0 || k%5==0) return -1;
        long long value=1;
        int ans=1;
        while(true){
            if(!value) return ans;
            value = 10*value+1;
            value = value%k;
            ans++;
        }
        return -1;
     }
};