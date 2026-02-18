class Solution {
public:
    int mod = 1e9+7;
    int add(int a,int b){
        return (a+b)%mod;
    }
    int multi(int a,int b){
        return (1ll*a*b) % mod;
    }
    int power(int x,int n){
        if(n<2) return n?x:1;
        return multi(power(x,n&1),power(multi(x,x),n/2));
    }
    int inverse(int x){
        return power(x,mod-2);
    }
    int nCr(int n,int r){
        vector<int> fact(n+1,1);
        for(int i=1;i<=n;i++){
            fact[i]=multi(i,fact[i-1]);
        }
        vector<int> invFact(n+1,1);
        invFact[n] = inverse(fact[n]);
        for(int i=n-1;i>=0;i--){
            invFact[i] = multi(i+1,invFact[i+1]);
        }
        return multi(fact[n],multi(invFact[r],invFact[n-r]));
    }
    int numberOfWays(int start, int end, int k) {
        int diff = abs(start-end);
        if((diff & 1) ^ (k & 1)) return 0;
        int mini = start - k;
        int maxi = start + k;

        if(mini<=end && end<=maxi){
            int gap = (end - mini)/2;
            return nCr(k,gap);
        }
        return 0;
    }
};