class Solution {
public:
    int mod=1e9+7;
    int multi(int a,int b){
        return (1ll*a*b)%mod;
    }
    int numberOfWays(string corridor) {
        int n=corridor.size();
        int totalCount = 0;
        for(auto it:corridor){
            totalCount+=(it=='S');
        }
        if(!totalCount || (totalCount%2)) return 0;
        int odd=-1,even=n;
        int count=0;
        int i=0;
        int res=1;
        while(i<n){
            if(corridor[i]=='S'){
                count++;
                if(count%2){
                    odd=i;
                }else{
                    even=i;
                }
                if(odd>even){
                    res=multi(res,odd-even);
                }
            }
            i++;
        }
        return res;
    }
};