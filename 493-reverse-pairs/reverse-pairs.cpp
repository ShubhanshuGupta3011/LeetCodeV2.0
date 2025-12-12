#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

class Solution {
public:
    using Pair = pair<long long,long long>;
    using ordered_multiset = tree<
        Pair,
        null_type,
        less<Pair>,
        rb_tree_tag,
        tree_order_statistics_node_update>;
    ordered_multiset os;
    long long global_uid = 0;
    long long insert_val(long long x) {
        int id = global_uid++;
        os.insert({x, id});
        return id;
    }
    long long count_smaller(long long x) {
        return os.order_of_key({x,-1});
    }
    int reversePairs(vector<int>& nums) {
        reverse(nums.begin(),nums.end());
        int ans=0;
        for(auto it:nums){
            ans += count_smaller(it);
            insert_val(1ll*2*it);
        }
        return ans;

    }
};