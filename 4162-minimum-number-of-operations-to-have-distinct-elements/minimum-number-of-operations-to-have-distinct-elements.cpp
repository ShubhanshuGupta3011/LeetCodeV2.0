class Solution {
public:
    int minOperations(vector<int>& nums) {
        reverse(nums.begin(),nums.end());
        map<int,int> mp;
        for(auto it:nums){
            mp[it]++;
        }
        int counter=nums.size();
        int ans=0;
        while(counter != mp.size()){
            // cout<<"counter = "<<counter<<endl;
            // cout<<"mp.size = "<<mp.size()<<endl;
            // cout<<endl;
            ans++;
            if(counter>3){
                counter-=3;
                int temp=3;
                while(temp--){
                    int ele = nums.back();
                    mp[ele]--;
                    if(mp[ele]==0){
                        mp.erase(ele);
                    }
                    nums.pop_back();
                }
            }else{
                break;
            }
        }
        return ans;
    }
};