class Solution {
public:
    int operationCost(string s){
        int n = s.size();
        int cnt = 0;
        int left = 0,right = n-1;

        while(left<right){
            int d = abs(s[left]-s[right]);
            cnt += min(d,26-d);
            left++;
            right--;
        }

        return cnt;
    }

    int minOperations(string s) {
        int ans = INT_MAX;
        int n = s.size();

        for(int i = 0 ; i<n ;i++){
            string str1 = s.substr(0,i);
            string str2 = s.substr(i , n-i);
            int cnt = operationCost(str2 + str1) + i;
            ans = min(ans,cnt);
        }

        return ans;
    }
};