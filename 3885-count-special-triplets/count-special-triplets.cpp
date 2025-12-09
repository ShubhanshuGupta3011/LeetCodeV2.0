class Solution {
public:
    int mod=1e9+7;
    int sixInverse = (mod+1)/6;
    int add(int a,int b){
        return (a+b)%mod;
    }
    int multi(int a,int b){
        return (1ll*a*b)%mod;
    }
    int nC3(int n){
        int ans=multi(n,multi(n-1,n-2));
        ans=multi(ans,sixInverse);
        return ans;
    }
    int helper(vector<int>& a,vector<int>& b){
        int ans=0;
        for(int i=0;i<a.size();i++){
            int index=lower_bound(b.begin(),b.end(),a[i])-b.begin();
            int before = index;
            int after = b.size()-index;
            ans=add(ans,multi(before,after));
        }
        return ans;
    }
    int specialTriplets(vector<int>& nums) {
        map<int,vector<int>> mp;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int ans=0;
        for(auto it:mp){
            int key=it.first;
            if(!key) {
                ans+=nC3(it.second.size());
                continue;
            }
            int key2 = 2*key;
            if(mp.find(key2)!=mp.end()){
                ans=add(ans,helper(mp[key],mp[key2]));
            }
        }
        return ans;
    }
};