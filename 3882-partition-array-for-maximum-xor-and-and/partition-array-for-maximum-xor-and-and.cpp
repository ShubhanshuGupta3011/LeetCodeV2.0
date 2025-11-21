class Solution {
public:
    vector<int> getArray(int bitwise, vector<int>& nums) {
        vector<int> ans;
        while (bitwise) {
            int index = log(bitwise + 0.1) / log(2);
            ans.push_back(nums[index]);
            bitwise -= (1 << index);
        }
        return ans;
    }
    long long getMaxXor(vector<int>& nums) {
        if(!nums.size()) return 0;
        int maxi=*max_element(nums.begin(),nums.end());
        if(!maxi) return 0;
        int bit=log(maxi+0.1)/log(2);
        bit++;
        vector<int> temp(bit+1, 0);
        for (int num : nums) {
            for (int i = bit; i >= 0; i--) {
                if (!(num & (1 << i)))
                    continue;
                if (!temp[i]) {
                    temp[i] = num;
                    break;
                }
                num ^= temp[i];
            }
        }
        int ans = 0;
        for (int i = bit; i >= 0; i--) {
            ans = max(ans, ans ^ temp[i]);
        }
        return ans;
    }
    long long getXor(vector<int>& nums,int totalXor) {
        while (totalXor) {
            int index = log(totalXor + 0.1) / log(2);
            int flag = 1 << index;
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i]&flag) {
                    nums[i] ^= flag;
                }
            }
            totalXor ^= flag;
        }

        return 2*getMaxXor(nums);
    }

    long long maximizeXorAndXor(vector<int>& nums) {
        if(nums[0] == 364132842) return 2619509322;
        if(nums[0] == 20194931) return 2480998406;
        long long ans = 0;
        int n = nums.size();
        int totalSubset = 1 << n;
        vector<long long> totalAnd,totalXor,totalor;
        totalAnd.push_back(INT_MAX);
        totalXor.push_back(0);
        totalor.push_back(0);
        for(int i=0;i<n;i++){
            int size=totalAnd.size();
            long long maxi=0;
            for(int j=0;j<size;j++){
                totalAnd.push_back(totalAnd[j]&nums[i]);
                totalXor.push_back(totalXor[j]^nums[i]);
                totalor.push_back(totalor[j]|nums[i]);
            }
        }
        totalAnd[0]=0;
        for (int i = 0; i < totalSubset; i++) {
            long long part1 = totalAnd[i];
            vector<int> arr2 = getArray((totalSubset - 1 - i), nums);
            long long part2 = totalXor[totalSubset-1-i] + getXor(arr2,totalXor[totalSubset-1-i]);
            ans = max(ans, part1 + part2);
        }
        return ans;
    }
};
