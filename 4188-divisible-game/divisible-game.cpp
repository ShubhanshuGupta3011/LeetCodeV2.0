class Solution {
public:
    int mod = 1e9+7;
    set<int> st;
    long long part = -1e9;
    void getFactor(int n){
        int flag = 1;
        for(int i=2;i<=sqrt(n);i++){
            if(n%i) continue;
            st.insert(i);
            st.insert(n/i);
        }
        if(flag){
            st.insert(n);
        }
    }
    long long kadane(vector<int>& arr){
        long long ans = INT_MIN;
        long long part = 0;
        for(auto it:arr){
            part += it;
            ans = max(ans,part);
            if(part < 0){
                part = 0;
            }
        }
        return ans;
    }
    long long getAns(vector<int>& nums,int k){
        vector<int> a;
        for(auto it:nums){
            if(it%k){
                a.push_back(-it);
            }else{
                a.push_back(it);
            }
        }
        long long value = kadane(a);
        // cout<<"k = "<<k<<" value = "<<value<<endl;
        return value;
    }
    int divisibleGame(vector<int>& nums) {
        st.insert(2);
        for(auto it:nums){
            if(it == 1) continue;
            getFactor(it);
        }
        long long ans = -1e18;
        int saveK = 2;
        for(auto it:st){
            long long part = getAns(nums,it);
            if(part > ans){
                ans = part;
                saveK = it;
            }
        }
        return (ans*saveK + mod) % mod;
    }
};