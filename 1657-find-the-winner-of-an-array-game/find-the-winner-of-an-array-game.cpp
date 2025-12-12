class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        map<int,int> mp;
        for(int i=1;i<n;i++){
            int first=arr[i-1];
            int second=arr[i];
            if(first>second){
                swap(arr[i],arr[i-1]);
                mp[first]++;
            }else{
                mp[second]=1;
            }
            if(mp[first]==k) return first;
            if(mp[second]==k) return second;
        }
        return *max_element(arr.begin(),arr.end());
    }
};