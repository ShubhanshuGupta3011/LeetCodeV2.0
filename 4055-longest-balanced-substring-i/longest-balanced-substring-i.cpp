class Solution {
public:
    int helper(vector<int>& arr){
        int maxi=*max_element(arr.begin(),arr.end());
        int count=0;
        for(int i=0;i<26;i++){
            if(arr[i] && arr[i]<maxi) return 0;
            if(arr[i]) count++;
        }
        return count*maxi;
    }
    int longestBalanced(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++){
            vector<int> arr(26,0);
            for(int j=i;j<s.size();j++){
                arr[s[j]-'a']++;
                ans=max(ans,helper(arr));
            }
        }
        return ans;
    }
};