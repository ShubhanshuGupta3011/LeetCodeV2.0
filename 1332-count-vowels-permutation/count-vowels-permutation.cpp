class Solution {
public:
    int MOD = 1e9+7;
    using T = vector<vector<int>>;
    T I = {
        {1,0,0,0,0},
        {0,1,0,0,0},
        {0,0,1,0,0},
        {0,0,0,1,0},
        {0,0,0,0,1}
    };
    T M = {
        {0,1,0,0,0},
        {1,0,1,0,0},
        {1,1,0,1,1},
        {0,0,1,0,1},
        {1,0,0,0,0}
    };
    int add(int a,int b){
        return (a+b) % MOD;
    }
    int multi(int a,int b){
        return (1ll*a*b) % MOD;
    }
    T multi(T a,T b){
        vector<vector<int>> ans(5,vector<int>(5,0));
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                for(int k=0;k<5;k++){
                    ans[i][j] = add(ans[i][j],multi(a[i][k],b[k][j]));
                }
            }
        }
        return ans;
    }
    T power(int n){
        T ans = I;
        T part = M;
        while(n){
            if(n%2) ans = multi(ans,part);
            part = multi(part,part);
            n=n/2;
        }
        return ans;
        
    }
    int countVowelPermutation(int n) {
        T res = power(n-1);
        int ans = 0;
        for(int i=0;i<5;i++){
            for(int j=0;j<5;j++){
                ans=add(ans,res[i][j]);
            }
        }
        return ans;
    }
};