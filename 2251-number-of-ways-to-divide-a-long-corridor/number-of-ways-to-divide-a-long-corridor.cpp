class Solution {
public:
    int mod=1e9+7;
    int multi(int a,int b){
        return (1ll*a*b)%mod;
    }
    int numberOfWays(string corridor) {
        int n=corridor.size();
        vector<int> posOfSeat;
        for(int i=0;i<n;i++){
            if(corridor[i]=='S'){
                posOfSeat.push_back(i);
            }
        }
        int totalSeat = posOfSeat.size();
        if((totalSeat & 1) || !totalSeat) return 0;
        vector<pair<int,int>> pairing;
        int res=1;
        for(int i=1;i<totalSeat;i+=2){
            pairing.push_back({posOfSeat[i-1],posOfSeat[i]});
        }
        for(int i=1;i<pairing.size();i++){
            int start=pairing[i-1].second;
            int end=pairing[i].first;
            res=multi(res,end-start);
        }
        return res;
    }
};