class Solution {
public:
    int setBit(long long n){
        return n ? 1 + setBit(n & (n-1)): 0;
    }
    int depth(long long n){
        if(n==1) return 0;
        return 1 + depth(setBit(n));
    }
    void update(int index,int depth,int diff,vector<vector<int>>& ft){
        while(index < ft.size()){
            ft[index][depth] += diff;
            index += (index & -index);
        }
    }
    int getSum(int index,int depth,vector<vector<int>>& ft){
        int ans = 0 ;
        while(index){
            ans += ft[index][depth];
            index = index & (index-1);
        }
        return ans;
    }
    vector<int> popcountDepth(vector<long long>& nums, vector<vector<long long>>& queries) {
        int n = nums.size();
        vector<int> depths(n);
        for(int i=0;i<n;i++){
            depths[i] = depth(nums[i]);
        }
        vector<vector<int>> ft(n+1,vector<int>(8,0));
        for(int i=0;i<n;i++){
            update(i+1,depths[i],1,ft);
        }
        vector<int> ans;
        for(auto it:queries){
            if(it[0]==1){
                int l = it[1];
                int r = it[2];
                int depth = it[3];
                int part = getSum(r+1,depth,ft) - getSum(l,depth,ft);
                ans.push_back(part);
            }else{
                int index = it[1];
                long long value = it[2];
                int oldDepth = depths[index];
                int newDepth = depth(value);
                nums[index] = value;
                depths[index] = newDepth;
                if(oldDepth != newDepth){
                    update(index+1,oldDepth,-1,ft);
                    update(index+1,newDepth,1,ft);
                }
            }
        }
        return ans;
    }
};