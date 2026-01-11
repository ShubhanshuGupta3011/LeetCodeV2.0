class Solution {
public:
    long long dp[20][2];
    string MinusOne(string s){
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='0'){
                s[i]='9';
            }else{
                s[i]--;
                return s;
            }
        }
        return "";
    }
    long long solving(int index,int tight,int limit,string s){
        if(index>=s.size()){
            return 1;
        }
        if(dp[index][tight] != -1) return dp[index][tight];
        long long ans=0;
        int d=tight?s[index]-'0':9;
        for(int i=0;i<=d;i++){
            int newTight = tight && (i==d);
            if(i>limit) break;
            ans=(ans+solving(index+1,newTight,limit,s));
        }
        return dp[index][tight] = ans;
    }
    long long solve(string s,int limit){
        memset(dp,-1,sizeof(dp));
        return solving(0,1,limit,s);
    }
    long long helper(long long n,string s,int limit){
        long long value = stol(s);
        if(n < value) return 0;
        string t = to_string(n);
        int sz = s.size();
        string temp="";
        while(sz--){
            temp=t.back()+temp;
            t.pop_back();
        }
        cout<<"t = "<<t<<" temp = "<<temp<<endl;
        if(temp < s){
            t=MinusOne(t);
        }
        return solve(t,limit);
    }
    long long numberOfPowerfulInt(long long start, long long finish, int limit, string s) {
        return helper(finish,s,limit)-helper(start-1,s,limit);
    }
};