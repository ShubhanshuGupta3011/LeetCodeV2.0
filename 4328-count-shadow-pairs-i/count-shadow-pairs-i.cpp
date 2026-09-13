#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

class Solution {
public:
    typedef tree<
        pair<int,int>,
        null_type,
        less<pair<int,int>>,
        rb_tree_tag,
        tree_order_statistics_node_update
    > ordered_set;

    vector<int> helper(vector<int>& nums){
        int n = nums.size();
        vector<int> ans(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() && nums[st.top()]>nums[i]){
                ans[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    long long shadowPairs(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        ordered_set os;
        for(int i = 0; i < n; i++){
            os.insert({nums[i], i});
        }
        vector<int> smallOnRight = helper(nums);
        for(int i=0;i<n;i++){
            int nextIndex = smallOnRight[i]-1;
            int part = (nextIndex-i);
            int count = os.order_of_key({nums[i], nextIndex + 1}) - os.order_of_key({nums[i], i}) - 1;
            part -= count;
            ans += part;
        }
        return ans;
    }
};