using ll = long long;
class Solution {
public:
    string kthSmallestPath(vector<int>& destination, int k) {
        int v = destination[0];
        int h = destination[1];

        vector<vector<ll>> nCr(31,vector<ll>(31,0));
        nCr[0][0] = 1;
        for(int i=1;i<31;i++){
            nCr[i][0] = 1;
            for(int j=1;j<31;j++){
                nCr[i][j] = nCr[i-1][j] + nCr[i-1][j-1];
            }
        }

        int n = v + h;
        string ans = "";
        while(n){

            if(v && h){
                ll kk = nCr[n-1][v];
                if(kk >= k){
                    ans += "H";
                    h--;
                }else{
                    ans += "V";
                    v--;
                    k -= kk;
                }
            }else{
                while(h--){
                    ans += "H";
                }
                while(v--){
                    ans += "V";
                }
                break;
            }
            n--;
        }

        return ans;
    }
};