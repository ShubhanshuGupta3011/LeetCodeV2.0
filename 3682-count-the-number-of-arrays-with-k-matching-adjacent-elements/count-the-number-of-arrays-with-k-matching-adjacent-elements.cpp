class Solution {
public:
    int mod=1e9+7;
    vector<int> fact;
    int multi(int a,int b){
        return (1ll*a*b)%mod;
    }
    int power(int x,int n){
        if(n<2) return n?x:1;
        return multi(power(x,n%2),power(multi(x,x),n/2));
    }
    int inverse(int x){
        return power(x,mod-2);
    }
    int countGoodArrays(int n, int m, int k) {
        fact.push_back(1);
        for(int i=1;i<=n;i++){
            fact.push_back(multi(i,fact[i-1]));
        }
        int res = m;
        res=multi(res,power(m-1,n-k-1));
        res = multi(res,fact[n-1]);
        res = multi(res,inverse(fact[k]));
        res = multi(res,inverse(fact[n-k-1]));
        return res;

        /*
        
        formula used is 

        nCr(n-1,k) * m * power(m-1,n-k-1);

        */
    }
};