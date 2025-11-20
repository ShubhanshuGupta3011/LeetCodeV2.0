class Solution {
public:
    vector<int> solve(vector<int>& val){
        vector<int> res(val.size()+1,1);
        for(int i=1;i<res.size()-1;i++){
            res[i]=val[i-1]+val[i];
        }
        return res;
    }
    vector<vector<int>> generate(int n) {
        if(n==1) return {{1}};
        vector<vector<int>> ans = {{1},{1,1}};
        if(n==2) return {{1},{1,1}};
        for(int i=2;i<n;i++){
            vector<int> part=solve(ans[i-1]);
            ans.push_back(part);
        }
        return ans;
    }
};