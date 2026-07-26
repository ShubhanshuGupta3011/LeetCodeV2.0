class Solution {
public:
    vector<int> fact;
    int mod = 1e9+7;
    int multi(int a,int b){
        return (1ll * a * b) % mod;
    }
    int power(int x,int n){
        if(n<2) return n?x:1;
        int f = power(x,n%2);
        int s = power(multi(x,x),n/2);
        return multi(f,s);
    }
    int inverse(int x){
        return power(x,mod-2);
    }
    int helper(int n,int r){
        return multi(fact[n],multi(inverse(fact[n-r]),inverse(fact[r])));
    }
    int countValidSequences(int n, int k) {
        fact.resize(n+1,1);
        for(int i=1;i<=n;i++){
            fact[i] = multi(fact[i-1],i);
        }
        int ans1 = helper(n-1,k-1);
        int ans2 = 0;
        if(n%2 == k%2){
            ans2 = helper((n+k)/2-1,k-1);
        }
        return (ans1-ans2+mod)%mod;
    }
};