class Solution {
public:
    vector<int> helping(unordered_set<int> umap){
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(auto it:umap){
            mini=min(mini,it);
            maxi=max(maxi,it);
        }
        return {mini,maxi};
    }
    vector<int> helper(vector<int>& nums, int start) {
        int n = nums.size();
        unordered_set<int> normal;
        unordered_set<int> change;
        int ops = 0;
        for (int i = 0; i < n; i++) {
            if ((nums[i] & 1) == ((i + start) & 1)) {
                normal.insert(nums[i]);
            } else {
                ops++;
                change.insert(nums[i] - 1);
                change.insert(nums[i] + 1);
            }
        }
        int maxi = *max_element(nums.begin(), nums.end());
        int mini = *min_element(nums.begin(), nums.end());
        if (change.size() == 0 || normal.size() == 0) {
            return {0, maxi - mini};
        }
        vector<int> a = helping(change);
        vector<int> b = helping(normal);
        if (change.size() == 2) {
            int gap1 = max(b[1],a[0]) - min(b[0],a[0]);
            int gap2 = max(a[1],b[1]) - min(b[0],a[1]);
            // cout<<"operation = "<<ops<<endl;
            // cout<<"gap1 = "<<gap1<<" gap2 = "<<gap2<<endl;
            // cout<<"--------------------------"<<endl;
            return {ops,min(gap1,gap2)};
        }
        // cout<<"operation = "<<ops<<endl;
        // cout<<"a = ";
        // cout<<"{"<<a[0]<<","<<a[1]<<"}"<<endl;
        // cout<<"b = ";
        // cout<<"{"<<b[0]<<","<<b[1]<<"}"<<endl;
        maxi = max(b[1],a[1]-2);
        mini = min(b[0],a[0]+2); 
        // cout<<"maxi = "<<maxi<<" mini = "<<mini<<endl;
        // cout<<"-------------------------------------"<<endl;
        int gap = maxi-mini;
        return {ops,gap};
    }
    vector<int> makeParityAlternating(vector<int>& nums) {
        vector<int> a = helper(nums, 0);
        vector<int> b = helper(nums, 1);
        if (a[0] != b[0])
            return a[0] < b[0] ? a : b;
        return {a[0], min(a[1], b[1])};
    }
};