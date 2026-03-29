class Solution {
public:
    int mod = 1e9 + 7;
    int multi(int a,int b){
        return (1ll * a * b) % mod;
    }
    int add(int a,int b){
        if(a+b >= mod) return a+b-mod;
        return a+b;
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
    int nCr(int n,int r,vector<int>& fact){
        if(n<r) return 0;
        int ans = fact[n];
        ans = multi(ans,inverse(fact[r]));
        ans = multi(ans,inverse(fact[n-r]));
        return ans;
    }
    int countVisiblePeople(int n, int pos, int k) {
        vector<int> fact(n+1,1);
        for(int i=1;i<=n;i++){
            fact[i] = multi(i,fact[i-1]);
        }
        return multi(2,nCr(n-1,k,fact));
    }
};