class Solution {
public:
    int mod=1e9+7;
    int multi(int a,int b){
        return (1ll*a*b)%mod;
    }
    int countPermutations(vector<int>& complexity) {
        int n=complexity.size();
        vector<int> fact(n,1);
        for(int i=1;i<n;i++){
            fact[i]=multi(fact[i-1],i);
        }
        int first=complexity[0];
        for(int i=1;i<n;i++){
            if(complexity[i]<=first) return 0;
        }
        return fact.back();
    }
};