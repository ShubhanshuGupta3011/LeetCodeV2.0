class Solution {
public:
    vector<int> fact;
    int mod = 1e9+7;
    int multi(int a,int b){
        return (1ll * a * b) % mod;
    }
    int power(int x,int n){
        if(n<2) return n?x:1;
        int f = power(x,n&1);
        int s = power(multi(x,x),n/2);
        return multi(f,s);
    }
    int inverse(int x){
        return power(x,mod-2);
    }
    int nCr(int n,int r){
        if(r>n) return 0;
        int ans = fact[n];
        ans = multi(ans,inverse(fact[r]));
        ans = multi(ans,inverse(fact[n-r]));
        return ans;
    }
    int numberOfSets(int n, int k) {
        fact.resize(n+k);
        fact[0]=1;
        for(int i=1;i<fact.size();i++){
            fact[i] = multi(fact[i-1],i);
        }
        return nCr(n+k-1,2*k);
    }
};