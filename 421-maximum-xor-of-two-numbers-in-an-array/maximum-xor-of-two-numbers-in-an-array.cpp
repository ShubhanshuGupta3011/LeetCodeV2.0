class Solution {
public:
    int isValid(vector<int>& nums,int ans,int mask){
        set<int> st;
        for(auto it:nums){
            st.insert(it & mask);
        }
        for(auto it:st){
            if(st.count(it ^ ans)){
                return 1;
            }
        }
        return 0;
    }
    int findMaximumXOR(vector<int>& nums) {
        int ans=0;
        int mask=0;
        for(int i=30;i>=0;i--){
            int bit = pow(2,i);
            int part = ans + bit;
            mask += bit;
            if(isValid(nums,part,mask)){
                ans=part;
            }
        }
        return ans;
    }
};