class Solution {
public:
    vector<int> fact;
    vector<int> count2;
    vector<int> count5;
    vector<int> inv2 = {0,1,0,7,0,0,0,3,0,9};
    vector<int> power2 = {6,2,4,8};
    int mod = 10;
    int multi(int a,int b){
        return (a*b) % mod;
    }
    int add(int a,int b){
        return (a+b) % mod;
    }
    int nCr(int n,int r){
        int two = count2[n] - count2[r] - count2[n-r];
        int five = count5[n] - count5[r] - count5[n-r];
        if(two && five) return 0;
        int ans = fact[n];
        ans = multi(ans,inv2[fact[r]]);
        ans = multi(ans,inv2[fact[n-r]]);
        return two ? multi(ans,power2[two & 3]): (five ? multi(ans,5) : ans) ;
    }
    int triangularSum(vector<int>& nums) {
        int n = nums.size();
        fact.resize(n,1);
        count2.resize(n,0);
        count5.resize(n,0);
        for(int i=1;i<n;i++){
            int value = i;
            int two = 0;
            int five = 0;
            while(value%2 == 0){
                value = value/2;
                two++;
            }
            while(value%5 == 0){
                value = value/5;
                five++;
            }
            fact[i] = multi(fact[i-1],value);
            count2[i] = two + count2[i-1];
            count5[i] = five + count5[i-1];
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            int comb = nCr(n-1,i);
            ans = add(ans,multi(comb,nums[i]));
        }
        return ans;
    }
};