#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
class Solution {
public:
    typedef tree<pair<long long,int>, null_type, less<pair<long long,int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

    long long countRatioSubarrays(vector<int>& nums, int a, int b) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] = nums[i]&1 ? a : -b ;
        }
        long long prefix = 0;
        long long ans = 0;
        ordered_set os;
        os.insert({0,0});
        for(int i=0;i<n;i++){
            prefix += nums[i];
            ans += os.order_of_key({prefix,INT_MAX});
            os.insert({prefix,i+1});
        }
        return ans;
    }
};