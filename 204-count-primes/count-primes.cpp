class Solution {
public:
    int countPrimes(int n) {
        if(n==0) return 0;
        vector<int> prime(n+1,1);
        prime[0]=0;
        prime[1]=0;
        for(int i=4;i<=n;i+=2){
            prime[i]=0;
        }
        for(int i=3;i<=sqrt(n+0.1);i+=2){
            if(prime[i]){
                for(int j=i*i;j<=n;j+=2*i){
                    prime[j]=0;
                }
            }
        }
        int ans=0;
        for(auto it:prime){
            ans+=it;
        }
        return ans-prime[n];
    }
};