class Solution {
public:
    struct Node {
        int hcf;
        int count;
    };
    int gcd(int a, int b) {
        if (a && b) {
            return gcd(b, a % b);
        }
        return a ? a : b;
    }
    vector<Node> seg;
    void push(int node) {
        seg[node].hcf = gcd(seg[2*node].hcf,seg[2*node+1].hcf);
        seg[node].count = seg[2*node].count + seg[2*node+1].count;
    }
    void build(int node, int l, int r, vector<int>& nums) {
        if (l == r) {
            seg[node].hcf = nums[l];
            seg[node].count = nums[l] ? 1 : 0;
            return;
        }
        int m = (l + r) / 2;
        build(2 * node, l, m, nums);
        build(2 * node + 1, m + 1, r, nums);
        push(node);
    }
    void update(int node, int l, int r, int index, int value,vector<int>& nums) {
        if (l == r) {
            seg[node].hcf = nums[l];
            seg[node].count = nums[l] ? 1 : 0;
            return;
        }
        int m = (l + r) / 2;
        if(index <= m){
            update(2 * node, l, m, index, value, nums);
        }else{
            update(2 * node + 1, m + 1, r, index, value, nums);
        }
        push(node);
    }
    int countGoodSubseq(vector<int>& nums, int p,
                        vector<vector<int>>& queries) {
        int n = nums.size();
        if(n==1) return 0;
        seg.resize(4 * n);
        for (int i = 0; i < n; i++) {
            if (nums[i] % p) {
                nums[i] = 0;
            } else {
                nums[i] = nums[i] / p;
            }
        }
        build(1, 0, n - 1, nums);
        int ans = 0;
        for (auto it : queries) {
            int index = it[0];
            int value = it[1];
            if (value % p) {
                value = 0;
            } else {
                value = value / p;
            }
            nums[index] = value;
            update(1, 0, n - 1, index, value, nums);

            if(seg[1].hcf != 1) continue;
            if(seg[1].count != n){
                ans++;
                continue;
            }else if(n>20){
                ans++;
                continue;
            }
            vector<int> preGcd(n);
            vector<int> postGcd(n);
            preGcd[0] = nums[0];
            for(int i=1;i<n;i++){
                preGcd[i] = gcd(preGcd[i-1],nums[i]);
            }
            postGcd[n-1] = nums[n-1];
            for(int i=n-2;i>=0;i--){
                postGcd[i] = gcd(postGcd[i+1],nums[i]);
            }
            if(postGcd[1] == 1 || preGcd[n-2] == 1){
                ans++;
                continue;
            }
            for(int i=1;i<n-1;i++){
                if(gcd(preGcd[i-1],postGcd[i+1]) == 1){
                    ans++;
                    break;
                }
            }
        }
        return ans;
    }
};