class Solution {
public:
    int mod = 1e9 + 7;
    vector<int> arr;
    int add(int a, int b) {
        if (a + b >= mod)
            return a + b - mod;
        return a + b;
    }

    int countArrays(vector<int>& digitSum) {
        if(*max_element(digitSum.begin(),digitSum.end()) > 31) return 0;
        int n = digitSum.size();
        arr.resize(5001, 0);
        vector<int> numberWithSum[32];
        for(int i=0;i<=5000;i++){
            arr[i] = arr[i/10] + i%10;
            numberWithSum[arr[i]].push_back(i);
        }
        vector<int> dp(5001, 0);
        for(int i=0;i<n;i++){
            vector<int> curr(5001,0);

            for(auto currNum : numberWithSum[digitSum[i]]){
                if(i==0){
                    curr[currNum] = 1;
                }else{
                    int maxIdx = upper_bound(
                        numberWithSum[digitSum[i - 1]].begin(),
                        numberWithSum[digitSum[i - 1]].end(),
                        currNum
                    ) - numberWithSum[digitSum[i - 1]].begin() - 1;

                    if(maxIdx >=0 ){
                        curr[currNum] = dp[numberWithSum[digitSum[i - 1]][maxIdx]];
                    }
                }
            }

            for(int i=1;i<=5000;i++){
                curr[i] = add(curr[i],curr[i-1]);
            }
            dp = curr;
        }

        return dp[5000];
    }
};