class Solution {
public:

    int MOD = 1e9+7;
    using T = vector<vector<int>> ;
    T I = {
        {1,0,0,0,0,0,0,0,0,0},
        {0,1,0,0,0,0,0,0,0,0},
        {0,0,1,0,0,0,0,0,0,0},
        {0,0,0,1,0,0,0,0,0,0},
        {0,0,0,0,1,0,0,0,0,0},
        {0,0,0,0,0,1,0,0,0,0},
        {0,0,0,0,0,0,1,0,0,0},
        {0,0,0,0,0,0,0,1,0,0},
        {0,0,0,0,0,0,0,0,1,0},
        {0,0,0,0,0,0,0,0,0,1}
    };
    T M = {
        {0,0,0,0,1,0,1,0,0,0},
        {0,0,0,0,0,0,1,0,1,0},
        {0,0,0,0,0,0,0,1,0,1},
        {0,0,0,0,1,0,0,0,1,0},
        {1,0,0,1,0,0,0,0,0,1},
        {0,0,0,0,0,0,0,0,0,0},
        {1,1,0,0,0,0,0,1,0,0},
        {0,0,1,0,0,0,1,0,0,0},
        {0,1,0,1,0,0,0,0,0,0},
        {0,0,1,0,1,0,0,0,0,0}
    };
    int add(int a,int b){
        return (a+b)%MOD;
    }
    int multi(int a,int b){
        return (1ll*a*b)%MOD;
    }
    T multi(T a,T b){
        vector<vector<int>> ans(10,vector<int>(10,0));
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                for(int k=0;k<10;k++){
                    ans[i][j] =add(ans[i][j],multi(a[i][k],b[k][j]));
                }
            }
        }
        return ans;
    }
    T power(T a,int n){
        if(n<2) return n?a:I;
        T f = power(a,n%2);
        T s = power(multi(a,a),n/2);
        return multi(f,s);
    }
    int knightDialer(int n) {
        T res = power(M,n-1);
        int ans=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                ans=add(ans,res[i][j]);
            }
        }
        return ans;
    }
};