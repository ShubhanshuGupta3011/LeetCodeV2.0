class Solution {
public:
    
    vector<int> sumChecker;
    string num;
    
    long long dpInc[16][2][11][136];
    long long inc(int index,int tight,int prev,int currSum){
        if(index == num.size()) return !sumChecker[currSum];
        if(dpInc[index][tight][1+prev][currSum] != -1) return dpInc[index][tight][1+prev][currSum];
        long long ans = 0;
        int d = tight ? (num[index]-'0') : 9;
        for(int i=0;i<=d;i++){
            if(i<=prev) continue;
            int newTight = tight && (i==d);
            if(prev==-1 && i==0){
                ans += inc(index+1,newTight,-1,currSum);
            }else{
                ans += inc(index+1,newTight,i,currSum+i);
            }
        }
        dpInc[index][tight][1+prev][currSum] = ans;
        return ans;
    }
    
    
    long long dpDec[16][2][11][136];
    long long dec(int index,int tight,int prev,int currSum){
        if(index == num.size()) return !sumChecker[currSum];
        if(dpDec[index][tight][prev][currSum] != -1) return dpDec[index][tight][prev][currSum];
        long long ans = 0;
        int d = tight ? (num[index]-'0') : 9;
        for(int i=0;i<=d;i++){
            if(i>=prev) continue;
            int newTight = tight && (i==d);
            if(prev==10 && i==0){
                ans += dec(index+1,newTight,10,currSum);
            }else{
                ans += dec(index+1,newTight,i,currSum+i);
            }
        }
        dpDec[index][tight][prev][currSum] = ans;
        return ans;
    }
    
    
    long long dpSum[16][2][136];
    long long sum(int index,int tight,int currSum){
        if(index == num.size()) return sumChecker[currSum];
        if(dpSum[index][tight][currSum] != -1) return dpSum[index][tight][currSum];
        long long ans = 0;
        int d = tight ? (num[index]-'0') : 9;
        for(int i=0;i<=d;i++){
            int newTight = tight && (i==d);
            ans += sum(index+1,newTight,currSum+i);
        }
        dpSum[index][tight][currSum] = ans;
        return ans;
    }
    
    
    long long helper(long long n){
        if(n<10) return 1+n;
        num = to_string(n);
        memset(dpSum, -1, sizeof(dpSum));
        memset(dpInc, -1, sizeof(dpInc));
        memset(dpDec, -1, sizeof(dpDec));
        
        long long countNumberWhoSumCheckIsOne = sum(0,1,0);
        long long countIncreasingButSumCheckerIsZero = inc(0,1,-1,0);
        long long countDecreasingButSumCheckerIsZero = dec(0,1,10,0);
        
        return countDecreasingButSumCheckerIsZero + countIncreasingButSumCheckerIsZero + countNumberWhoSumCheckIsOne;
    }
    int check(int n){
        if(n<10) return 1;
        string s = to_string(n);
        int isIncrease = true;
        int isDecrese = true;
        for(int i=1;i<s.size();i++){
            if(s[i] >= s[i-1]){
                isDecrese = false;
            }
            if(s[i] <= s[i-1]){
                isIncrease = false;
            }
        }
        return isIncrease || isDecrese;
    }
    long long countFancy(long long l, long long r) {
        for(int i=0;i<=135;i++){
            sumChecker.push_back(check(i));
        }
        return helper(r) - helper(l-1);
    }
};