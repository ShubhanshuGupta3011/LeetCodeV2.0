class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        unordered_set<int> st;
        for(auto it:nums){
            st.insert(it);
        }
        while(st.count(lower)){
            lower++;
        }
        while(st.count(upper)){
            upper--;
        }
        if(lower > upper) return {};
        vector<int> arr(1+upper,1);
        for(auto it:st){
            if(lower<it && it<upper){
                arr[it] = 0;
            }
        }
        for(int i=lower+1;i<=upper;i++){
            if(arr[i]){
                arr[i] = 1+arr[i-1];
            }
        }

        vector<vector<int>> ans;
        for(int i=upper;i>=lower;i--){
            if(arr[i] == 0) continue;
            ans.push_back({i-arr[i]+1,i});
            i -= arr[i];
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};