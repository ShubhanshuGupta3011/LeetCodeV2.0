class Solution {
public:
    vector<vector<int>> dial = {
        {0,1,2,3,4,5,4,3,2,1},
        {1,0,1,2,3,4,5,4,3,2},
        {2,1,0,1,2,3,4,5,4,3},
        {3,2,1,0,1,2,3,4,5,4},
        {4,3,2,1,0,1,2,3,4,5},
        {5,4,3,2,1,0,1,2,3,4},
        {4,5,4,3,2,1,0,1,2,3},
        {3,4,5,4,3,2,1,0,1,2},
        {2,3,4,5,4,3,2,1,0,1},
        {1,2,3,4,5,4,3,2,1,0}
    };
    int minRotations(int n, string s) {
        if(n==1) return dial[0][s[0]-'0'];
        int prev = 0;
        vector<int> pre(n,0);
        pre[0] = dial[0][s[0]-'0'];
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + dial[s[i-1]-'0'][s[i]-'0'];
        }
        vector<int> post(n,0);
        post[n-2] = dial[s[n-1]-'0'][s[n-2]-'0'];
        for(int i=n-3;i>=0;i--){
            post[i] = post[i+1] + dial[s[i+1]-'0'][s[i]-'0'];
        }
        int ans = pre.back();
        for(int i=0;i<n-1;i++){
            ans = min(ans,pre[i] + post[i+1] + dial[s[i]-'0'][s.back()-'0']);
        }
        ans = min(ans,post[0] + dial[0][s.back()-'0']);
        return ans;

    }
};