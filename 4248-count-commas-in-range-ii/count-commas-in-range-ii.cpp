class Solution {
public:
    int getLog(long long n){
        if(n<1000) return 0;
        return 1+getLog(n/1000);
    }
    long long countCommas(long long n) {
        vector<long long> arr(6,999);
        for(int i=1;i<6;i++){
            arr[i] = 1000 * arr[i-1];
        }
        for(int i=0;i<6;i++){
            arr[i] = i * arr[i];
        }
        long long index = getLog(n);
        cout<<log(n)/log(10)<<endl;
        long long ans = 0;
        for(int i=0;i<index;i++){
            ans += arr[i];
        }
        long long low = pow(1000,index);
        ans += (n-low+1) * index;
        return ans;
    }
};