class Solution {
public:
    int mask = (1<<15)-1;
    vector<int> res;

    vector<int> largestPower(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++){
            nums[i] &= mask;
        }
        vector<vector<int>> level(n+1);
        level[n] = nums;
        for(int bit=14;bit>=0;bit--){
            int currMask = 1<<bit;
            for(int l=0;l<=n;l++){
                vector<int> on,off;
                if(level[l].size() == 0) continue;
                for(auto it:level[l]){
                    if(it & currMask){
                        on.push_back(it);
                    }else{
                        off.push_back(it);
                    }
                }
                int up = off.size();
                level[l] = off;
                for(auto it:on){
                    level[l-up].push_back(it);
                }
                if(up){
                    break;
                }
            }

        }
        vector<int> per;
        for(int i=0;i<=n;i++){
            for(auto it:level[i]){
                per.push_back(it);
            }
        }
        for(int i=0;i<15;i++){
            int currMask = 1<<i;
            int count = 0;
            for(auto it:per){
                if(it & currMask){
                    count++;
                }else{
                    break;
                }
            }
            res.push_back(count);
        }
        reverse(res.begin(),res.end());
        return res;
    }
};