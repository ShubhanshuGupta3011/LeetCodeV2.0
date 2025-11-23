class Solution {
public:
    int mod=1e9+7;
    int minus(int a){
        if(a<0) return (a%mod+mod)%mod;
        return a%mod;
    }
    int add(int a,int b){
        return (a+b)%mod;
    }
    int multi(int a,int b){
        return (1ll*a*b)%mod;
    }
    int power(int x,int n){
        int ans=1;
        int part=x;
        while(n){
            if(n%2){
                ans=multi(ans,part);
            }
            part=multi(part,part);
            n=n/2;
        }
        return ans;
    }
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> sum(n),digit(n),number(n);
        int FirstDigit = s[0]-'0';
        sum[0]=FirstDigit;
        number[0]=FirstDigit;
        digit[0]=FirstDigit?1:0;

        for(int i=1;i<n;i++){
            int value=s[i]-'0';
            sum[i]=sum[i-1];
            digit[i]=digit[i-1];
            number[i]=number[i-1];
            if(value){
                sum[i]=sum[i-1]+value;
                digit[i]=digit[i-1]+1;
                number[i]=add(value,multi(10,number[i-1]));   
            }
        }
        vector<int> res;

        for(auto it:queries){
            int l=it[0];
            int r=it[1];
            if(!l){
                res.push_back(multi(sum[r],number[r]));
                continue;
            }
            int Sum = sum[r]-sum[l-1];
            int Digit = digit[r]-digit[l-1];
            int Power = power(10,Digit);
            int rr = number[r];
            int ll = multi(number[l-1],Power); 
            int subtract = minus(rr-ll);
            res.push_back(multi(subtract,Sum));
        }
        return res;
    }
};