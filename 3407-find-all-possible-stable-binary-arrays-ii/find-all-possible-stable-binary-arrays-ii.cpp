class Solution {
public:
    int mod = 1e9+7;
    int add(int a,int b){
        return (a+b > mod) ? a+b-mod : a+b;
    }
    int minus(int a,int b){
        return a<b ? a-b+mod : a-b;
    }
    int numberOfStableArrays(int zero, int one, int limit) {
        vector<vector<int>> dp0(1+zero,vector<int>(1+one,0));
        vector<vector<int>> dp1(1+zero,vector<int>(1+one,0));
        for(int i=0;i<=min(zero,limit);i++) dp0[i][0] = 1;
        for(int j=0;j<=min(one,limit);j++) dp1[0][j] = 1;
        for(int i=1;i<=zero;i++){
            for(int j=1;j<=one;j++){
                dp0[i][j] = add(dp0[i-1][j],dp1[i-1][j]);
                int gap = i - limit - 1;
                if(gap>=0) dp0[i][j]=minus(dp0[i][j],dp1[gap][j]);
                dp1[i][j] = add(dp1[i][j-1],dp0[i][j-1]);
                gap = j - limit - 1;
                if(gap>=0) dp1[i][j]=minus(dp1[i][j],dp0[i][gap]);
            }
        }
        return add(dp0[zero][one],dp1[zero][one]);
    }
};