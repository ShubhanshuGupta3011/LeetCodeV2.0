class Solution {
public: 
    int ans=-1;
    int helper(long long start,int n,int k){
        long long low=start, count=1,high;
        int res=0;
        while(low<=n){
            high=low+count-1;
            high=min(high,1ll*n);
            count=high-low+1;
            res+=count;
            low=10*low;
            count=10*count;
        }
        return res;
    }
    void dfs(long long start,int n,int& k){
        if(ans!=-1) return;
        if(start>n) return;
        if(k==1) {
            ans=start;
            return;
        }
        int count = helper(start,n,k);
        if(count<k){
            k-=count;
        }else{
            k--;
            for(int i=0;i<10;i++){
                dfs(10*start+i,n,k);
            }
        }
    }
    int findKthNumber(int n, int k) {
        for(int i=1;i<10;i++){
            dfs(i,n,k);
        }
        return ans;
    }
};