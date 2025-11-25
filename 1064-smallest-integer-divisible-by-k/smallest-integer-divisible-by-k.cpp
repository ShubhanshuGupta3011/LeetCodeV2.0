class Solution {
public:
    int smallestRepunitDivByK(int k) {
        if(k%2==0) return -1;
        if(k%5==0) return -1;
        int sum=0;
        int ans=0;
        while(true){
            ans++;
            sum=(10*sum+1)%k;
            if(sum==1 && ans!=1) return -1;
            if(sum==0) break;
        }
        return ans;
    }
};