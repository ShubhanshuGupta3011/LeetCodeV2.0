class Solution {
public:
    using T = vector<vector<int>>;
    int MOD = 1e9+7;
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
    T power(T a,int n,T I){
        if(n<2) return n?a:I;
        T f = power(a,n%2,I);
        T s = power(multi(a,a),n/2,I);
        return multi(f,s);
    }
    int knightDialer(int n) {
        vector<vector<int>> I(10,vector<int>(10,0));
        vector<vector<int>> M(10,vector<int>(10,0));
        for(int i=0;i<10;i++){
            I[i][i]=1;
        }
        vector<vector<int>> connection = {
            {0,4},{0,6},{1,6},{1,8},{2,7},{2,9},{3,4},{3,8},{4,9},{6,7}
        };
        for(auto it:connection){
            M[it[0]][it[1]]=1;
            M[it[1]][it[0]]=1;
        }
        T res = power(M,n-1,I);
        int ans=0;
        for(int i=0;i<10;i++){
            for(int j=0;j<10;j++){
                ans=add(ans,res[i][j]);
            }
        }
        return ans;
    }
};