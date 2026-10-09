class Solution {
public:
    int mod = 1e9 + 7;
    int base = 1e5 + 3;
    
    int multi(int a,int b){
        return (1ll * a * b) % mod;
    }
    int add(int a,int b){
        return a+b>=mod ? a+b-mod : a+b;
    }
    int sub(int a,int b){
        return (a>=b) ? (a-b) : (a-b+mod);
    }

    int power(int x,int n){
        if(n<2) return n?x:1;
        int f = power(x,n&1);
        int s = power(multi(x,x),n/2);
        return multi(f,s);
    }
    int isValid(vector<int>& nums,int mid){
        unordered_map<int,int> freq;
        int fact = power(base,mid);
        int key = 0;
        for(int i=0;i<mid;i++){
            key = multi(key,base);
            key = add(key,nums[i]);
        }
        freq[key]++;

        for(int i=mid;i<nums.size();i++){
            key = multi(key,base);
            key = add(key,nums[i]);
            key = sub(key,multi(nums[i-mid],fact));
            freq[key]++;
        }
        for(auto it:freq){
            if(it.second == 1) return 1;
        }
        return 0;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int low = 1;
        int high = n;
        int ans = 0;
        while(low <= high){
            int mid = (low + high)/2;

            if(isValid(nums,mid)){
                ans = mid;
                high = mid - 1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};