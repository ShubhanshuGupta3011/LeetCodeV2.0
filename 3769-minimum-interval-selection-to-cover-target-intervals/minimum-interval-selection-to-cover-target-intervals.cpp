class Solution {
public:
    int minSelection(vector<vector<int>>& a, vector<vector<int>>& b) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());

        int i = 0;
        int j = 0;
        int n = a.size();
        int m = b.size();
        int maxi = -1;
        int curr = b[0][0];
        int ans = 0;

        while(j<m){
            int pMax = maxi;
            while(i < n && a[i][0] <= curr) {
                maxi = max(maxi, a[i][1]);
                i++;
            }
            if(pMax == maxi) return -1;
            ans++;
            while(j < m && b[j][1] <= maxi) {
                j++;
            }
            if(j == m) return ans;

            curr = max(maxi,b[j][0]);
        }
        return ans;
    }
};