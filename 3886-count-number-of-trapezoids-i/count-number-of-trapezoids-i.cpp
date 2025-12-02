class Solution {
public:
    int mod=1e9+7;
    int add(int a,int b){
        return (a+b)%mod;
    }
    int multi(int a,int b){
        return (1ll*a*b)%mod;
    }
    int nC2(int n){
        int ans=multi(n,n-1);
        ans=multi(ans,(mod+1)/2);
        return ans;
    }
    int countTrapezoids(vector<vector<int>>& points) {
        map<int,vector<int>> mp;
        for(auto it:points){
            mp[it[1]].push_back(it[0]);
        }
        vector<int> arr;
        for(auto it:mp){
            int size = it.second.size();
            arr.push_back(nC2(size));
        }
        int sum=0;
        for(auto it:arr){
            sum=add(sum,it);
        }
        int ans=0;
        for(auto it:arr){
            ans=add(ans,multi(it,sum-it));
        }
        ans=multi(ans,(mod+1)/2);
        return ans;
    }
};