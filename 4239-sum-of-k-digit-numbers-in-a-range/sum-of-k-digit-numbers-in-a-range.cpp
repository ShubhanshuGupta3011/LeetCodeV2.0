class Solution {
public:
    int mod = 1e9 + 7;
    int multi(int a,int b){
        return (1ll*a*b) % mod;
    }
    int power(int x,int n){
        if(n<2) return n ? x:1;
        int f = power(x,n%2);
        int s = power(multi(x,x),n/2);
        return multi(f,s);
    }
    int inverse(int x){
        return power(x,mod-2);
    }
    int sumOfNumbers(int l, int r, int k) {
        int fact = power(10,k);
        fact--;
        fact = multi(fact,inverse(9));
        int gap = r - l + 1;
        fact = multi(fact,power(gap,k-1));
        int sum = 0;
        for(int i=l;i<=r;i++){
            sum+=i;
        }
        fact = multi(fact,sum);
        return fact;
    }
};