class Solution {
public:
    bool isAllOddPossible(vector<int>& nums1){
        int smallestOdd = INT_MAX;
        for(auto it:nums1){
            if(!(it & 1)) continue;
            smallestOdd = min(smallestOdd,it);
        }
        return true;
    }
    bool uniformArray(vector<int>& nums1) {
        return true;
    }
};