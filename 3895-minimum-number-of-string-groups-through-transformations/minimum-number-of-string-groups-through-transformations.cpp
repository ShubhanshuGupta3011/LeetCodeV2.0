class Solution {
public:
    int mod = 1e9 + 7;
    int inverse31;
    int multi(int a,int b){
        return (1ll*a*b)%mod;
    }
    int add(int a,int b){
        return (a+b) % mod;
    }
    int minus(int a,int b){
        return ((a-b)%mod + mod) % mod;
    }
    int power(int x,int n){
        if(n<2) return n?x:1;
        int f = power(x,n&1);
        int s = power(multi(x,x),n/2);
        return multi(f,s);
    }
    int inverse(int x){
        return power(x,mod-2);
    }
    int helper(string s){
        int n = s.size();
        for(int i=0;i<n;i++){
            s += s[i];
        }
        // cout<<"s = "<<s<<endl;
        int ans = INT_MAX;
        int part = 0;
        for(int i=0;i<n;i++){
            part=multi(part,31);
            part=add(part,s[i]-'a'+1);
        }
        ans = min(ans,part);
        int fact = power(31,n);
        for(int i=n;i<2*n;i++){
            part = multi(part,31);
            part = add(part,s[i]-'a'+1);
            part = minus(part,multi(fact,s[i-n]-'a'+1));
            ans = min(ans,part);
        }
        // cout<<"ans = "<<ans<<endl;
        return ans;
    }
    int minimumGroups(vector<string>& words) {
        /*
        leet
        le et
        lele etet
        el et
        */
        unordered_map<int,int> freq;
        inverse31 = inverse(31);
        for(auto word:words){
            string odd = "";
            string even = "";
            for(int i=0;i<word.size();i++){
                if(i&1){
                    odd += word[i];
                }else{
                    even += word[i];
                }
            }
            int f = helper(odd);
            int s = helper(even);
            f = multi(f,power(31,even.size()));
            f = add(f,s);
            freq[f]++;
        }
        return freq.size();
    }
};