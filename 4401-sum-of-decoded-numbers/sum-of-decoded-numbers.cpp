class Solution {
public:
    using ll = long long;
    int mod = 1e9+7;
    ll multi(ll a,ll b){
        return (1ll*a*b)%mod;
    }
    ll add(ll a,ll b){
        return (a+b)>=mod?(a+b-mod):a+b;
    }
    ll power(ll x,ll n){
        if(n<2) return n?x:1;
        ll f = power(x,n&1);
        ll s = power(multi(x,x),n/2);
        return 1ll*multi(f,s);
    }
    ll helper(ll n){
        ll w = n%10;
        string d = to_string(n/10);
        string x,y;
        for(int i=0;i<d.size();i++){
            if(i<w){
                x+=d[i];
            }else{
                y+=d[i];
            }
        }
        cout<<"x = "<<x<<" y = "<<y<<endl;
        ll xx = stol(x);
        ll yy = stol(y);
        xx = xx % mod;
        yy = yy % (mod-1);
        return power(xx,yy);      
    }
    int sumDecoded(vector<long long>& nums) {
        ll ans = 0;
        for(auto it:nums){
            ans = add(ans,helper(it));
        }
        return ans;
    }
};