class Solution {
public:
    bool isAllOddPossible(vector<int>& nums1){
        int smallestOdd = INT_MAX;
        for(auto it:nums1){
            if(!(it & 1)) continue;
            smallestOdd = min(smallestOdd,it);
        }
        for(auto it:nums1){
            if(it&1) continue;
            if(it < smallestOdd) return false;
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        int odd = 0;
        int even = 0;
        for(auto it:nums1){
            odd += (it&1);
            even += !(it&1);
        }
        if(!odd || !even) return true;
        return isAllOddPossible(nums1);
    }
};