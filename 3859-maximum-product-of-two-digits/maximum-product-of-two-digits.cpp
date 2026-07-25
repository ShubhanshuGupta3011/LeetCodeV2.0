class Solution {
public:
    int maxProduct(int n) {
        vector<int> arr(10,0);
        while(n){
            arr[n%10]++;
            n=n/10;
        }
        int ans = 0;
        int big = 0;
        for(int i=0;i<10;i++){
            if(arr[i]==0) continue;
            if(arr[i] == 1){
                ans = i * big;
            }else{
                ans = i * i;
            }
            big = i;
        }
        return ans;
    }
};