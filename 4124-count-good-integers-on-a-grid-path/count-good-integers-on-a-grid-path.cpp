class Solution {
public:
    string s;
    long long dp[16][2][10];
    long long helper(int index,int tight,int prev){
        if(index == 16) return 1;
        if(dp[index][tight][prev] != -1) return dp[index][tight][prev];
        int d = tight ? s[index]-'0': 9;
        long long ans = 0;
        for(int i=0;i<=d;i++){
            int newTight = tight && (i==d);
            if(path[index]){
                if(i<prev) continue;
                ans += helper(index+1,newTight,i);
            }else{
                ans += helper(index+1,newTight,prev);
            }
        }
        return dp[index][tight][prev] = ans;
    }
    long long solve(long long n){
        s = to_string(n);
        while(s.size()!=16){
            s = '0' + s;
        }
        memset(dp,-1,sizeof(dp));
        return helper(0,1,0);
    }
    vector<int> path = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    long long countGoodIntegersOnPath(long long l, long long r, string directions) {
        int row = 0;
        int col = 0;
        for(auto it:directions){
            row += (it=='D');
            col += (it=='R');
            path[4*row + col] = 1;
        }
        return solve(r) - solve(l-1);
    }
};