class Solution {
public:
    int k,m;
    vector<long long> power;
    long long helper(long long a,long long b){
        vector<int> dp(63,0);
        while(a){
            int index = log2(a);
            dp[index]--;
            a-=pow(2,index);
        }
        while(b){
            int index = log2(b);
            dp[index]++;
            b-=pow(2,index);
        }
        long long ans=0;
        for(int i=62;i>=0;i--){
            if(dp[i]){
                ans += (1ll* dp[i] * power[i]);
                if(ans < 0){
                    ans=0;
                }
            }
        }
        return ans;
    }
    int isValid(vector<int>& nums,int currAns){
        long long LastBit = currAns;
        while((LastBit & (LastBit-1)) != 0 ){
            LastBit += (LastBit & -LastBit);
        }
        vector<vector<long long>> arr;
        for(int i=0;i<nums.size();i++){
            int currValue = nums[i];
            if((currValue & currAns) == currAns){
                arr.push_back({0,i});
            }else{
                currValue = currValue % LastBit;
                if(currValue > currAns){
                    arr.push_back({helper(currValue,currAns),i});
                }else{
                    arr.push_back({currAns-currValue,i});
                }
            }
        }
        sort(arr.begin(),arr.end());
        long long K=0;
        for(int i=0;i<m;i++){
            K+=arr[i][0];
        }
        int ans=0;
        if(K<=k){
            for(int i=0;i<m;i++){
                int diff = arr[i][0];
                int index = arr[i][1];
                nums[index] += diff;
            }
            k-=K;
            ans=1;
        }
        return ans;
    }
    int maximumAND(vector<int>& nums, int _k, int _m) {
        power.resize(63);
        power[0]=1;
        for(int i=1;i<63;i++){
            power[i]=2*power[i-1];
        }
        k=_k;
        m=_m;
        int ans = 0;
        int currAns = 0;
        for(int i=30;i>=0;i--){
            int currAns = ans+pow(2,i);
            if(isValid(nums,currAns)){
                ans=currAns;
            }
        }
        return ans;
    }
};