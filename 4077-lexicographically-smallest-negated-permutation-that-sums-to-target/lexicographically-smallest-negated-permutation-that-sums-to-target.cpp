class Solution {
public:
    long long totalSumTilln(int n){
        long long maxi = 1ll*n*(n+1);
        maxi=maxi/2;
        return maxi;
    }
    vector<int> lexSmallestNegatedPerm(int n, long long target) {
        long long maxi = totalSumTilln(n);
        if(target>maxi) return {};
        if(target+maxi<0) return {};
        int rem1=maxi%2;
        int rem2=(2+target%2)%2;
        if(rem1!=rem2) return {};
        vector<int> res;
        while(n){
            maxi = totalSumTilln(n-1);
            if(target+n <= maxi){
                res.push_back(-n);
                target+=n;
            }else{
                res.push_back(n);
                target-=n;
            }
            n--;
        }
        sort(res.begin(),res.end());
        return res;
    }
};