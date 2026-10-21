class Solution {
public:
    vector<int> arr;
    vector<int> seg;
    void update(int node,int low,int high,int index){
        if(low>index || high<index){
            return;
        }
        if(low == high){
            seg[node] = arr[index];
            return;
        }
        int mid = (low + high)/2;
        update(2*node+1,low,mid,index);
        update(2*node+2,mid+1,high,index);
        seg[node] = max(seg[2*node+1],seg[2*node+2]);
    }
    int getMax(int node,int low,int high,int l,int r){
        if(low>r || high<l){
            return 0;
        }
        if(l<=low && high<=r){
            return seg[node];
        }
        int mid = (low + high)/2;
        int left = getMax(2*node+1,low,mid,l,r);
        int right = getMax(2*node+2,mid+1,high,l,r);
        return max(left,right);
    }
    int lengthOfLIS(vector<int>& nums) {
        
        int n = nums.size();
        map<int,vector<int>> mp;
        for(int i=0;i<n;i++){
            mp[nums[i]].push_back(i);
        }
        int rank = 1;
        for(auto it:mp){
            for(auto itt:it.second){
                nums[itt] = rank;
            }
            rank++;
        }
        int maxi = n + 5;
        arr.resize(maxi);
        seg.resize(4*maxi);
        int ans = 0;
        for(int i=n-1;i>=0;i--){
            int l = 1 + nums[i];
            int r = n + 2;
            int part = getMax(0,0,maxi-1,l,r);
            ans = max(ans, 1 + part);
            arr[nums[i]] = 1 + part;
            update(0,0,maxi-1,nums[i]);
        }
        return ans;
    }
};