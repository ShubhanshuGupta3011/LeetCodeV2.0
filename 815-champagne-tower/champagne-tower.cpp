class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> result(101,0.0);
        result[0] = poured;
        double ans;
        for(int i=0;i<100;i++){
            vector<double> nextResult(101,0.0);
            for(int j=0;j<=i;j++){
                if(result[j] >= 1){
                    nextResult[j] += (result[j]-1)/2.0;
                    nextResult[j+1] += (result[j]-1)/2.0;
                }
                if(i==query_row && j==query_glass){
                    ans = result[j];
                }
            }
            result = nextResult;
        }
        return ans>=1.0 ? 1.0 : ans;
    }
};