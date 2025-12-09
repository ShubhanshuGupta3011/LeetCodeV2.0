class NumArray {
public:
    vector<int> seg;
    void build(int node,int left,int right,vector<int>& nums){
        if(left==right){
            seg[node]=nums[left];
            return ;
        }
        int mid=(left+right)/2;
        build(2*node+1,left,mid,nums);
        build(2*node+2,mid+1,right,nums);
        seg[node]=seg[2*node+1]+seg[2*node+2];
    }
    int getSum(int node,int left,int right,int l,int r){
        if(left>=l && right<=r) return seg[node];
        if(right<l || r<left) return 0;
        int mid=(left+right)/2;
        return getSum(2*node+1,left,mid,l,r)+getSum(2*node+2,mid+1,right,l,r);
    }
    NumArray(vector<int>& nums) {
        int n=nums.size();
        seg.resize(4*n);
        build(0,0,n-1,nums);
    }

    int sumRange(int left, int right) {
        int n=seg.size()/4;
        return getSum(0,0,n-1,left,right);
    }
    void updating(int node,int left,int right,int index,int diff){
        if(index < left || index > right) return;   
        seg[node] += diff;
        if(left == right) return;
        int mid = (left+right)/2;
        if(index <= mid) updating(2*node+1,left,mid,index,diff);
        else updating(2*node+2,mid+1,right,index,diff);
    }
    void update(int index, int val) {
        int n=seg.size()/4;
        int curr = sumRange(0,index)-(index?sumRange(0,index-1):0);
        int diff = val-curr;
        updating(0,0,n-1,index,diff);
    }
    
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */