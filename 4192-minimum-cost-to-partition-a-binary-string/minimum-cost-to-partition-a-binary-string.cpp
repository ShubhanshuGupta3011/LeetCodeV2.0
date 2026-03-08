class Solution {
public:
    long long solve(string& s, int& ecost, int& fcost, int l, int r,vector<int>& pref){
        int L = r-l;
        int X = pref[r] - pref[l];

        long long cost;
        if(X ==0)
            cost = fcost;
        else
            cost = 1LL*L*X*ecost;
        if(L%2)
            return cost;
        int m = (l + r)/2;
        long long split = solve(s,ecost,fcost,l,m,pref)+solve(s,ecost,fcost,m,r,pref);
        return min(cost,split);
    }
    long long minCost(string s, int encCost, int flatCost) {
        int n = s.size();
        vector<int> pref(n+1,0);
        for(int i = 0 ; i < n ; i++)
            pref[i+1] = pref[i] + (s[i]=='1');
        return solve(s,encCost,flatCost,0,n,pref);
    }
};