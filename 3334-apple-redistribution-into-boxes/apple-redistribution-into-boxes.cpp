class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        sort(capacity.rbegin(),capacity.rend());
        int ans=0;
        int sum=0;
        for(auto it:apple){
            sum+=it;
        }
        for(auto it:capacity){
            ans++;
            if(sum>it){
                sum-=it;
            }else{
                sum-=it;
                break;
            }
        }
        return ans;
    }
};