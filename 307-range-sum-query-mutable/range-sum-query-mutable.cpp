class NumArray {
public:
    vector<int> ft = {0};

    NumArray(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            ft.push_back(0);
        }
        for(int i=0;i<nums.size();i++){
            int j=i+1;
            while(j<ft.size()){
                ft[j]+=nums[i];
                j+=(j&(-j));
            }
        }
    }
    int helper(int index){
        int ans=0;
        while(index){
            ans+=ft[index];
            index-=(index&(-index));
        }
        return ans;
    }
    void update(int index, int val) {
        int curr = helper(index+1)-helper(index);
        int diff = val-curr;
        index++;
        while(index<ft.size()){
            ft[index]+=diff;
            index += (index&(-index));
        }
    }
    
    int sumRange(int left, int right) {
        left++;
        right++;
        return helper(right)-helper(left-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */