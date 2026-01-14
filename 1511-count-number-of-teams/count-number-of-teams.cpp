class Solution {
public:
    vector<int> ft;
    void up(int i,int diff){
        while(i<ft.size()){
            ft[i]+=diff;
            i+=(i&-i);
        }
    }
    int gs(int i){
        if(!i) return 0;
        return ft[i]+gs(i&(i-1));
    }
    int helper(vector<int>& r){
        ft.resize(100001,0);
        int n=r.size();
        vector<int> cs(n);
        vector<int> cb(n);
        for(int i=0;i<n;i++){
            cs[i] = gs(r[i]-1);
            cb[i] = gs(100000) - gs(r[i]);
            up(r[i],1);
        }
        int ans=0;
        for(int k=n-1;k>=0;k--){
            for(int j=k-1;j>=0;j--){
                if(r[j] == r[k]) continue;
                if(r[j] < r[k]){
                    ans += cs[j];
                }else{
                    ans += cb[j];
                }
            }
        }
        return ans;
    }
    int numTeams(vector<int>& r) {
        return helper(r);
    }
};