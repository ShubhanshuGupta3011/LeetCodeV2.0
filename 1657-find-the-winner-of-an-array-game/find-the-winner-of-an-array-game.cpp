class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        int n=arr.size();
        int currWin=0;
        for(int i=1;i<n;i++){
            int first=arr[i-1];
            int second=arr[i];
            if(first>second){
                swap(arr[i],arr[i-1]);
                currWin++;
                if(currWin==k) return first;
            }else{
                currWin=1;
                if(currWin==k) return second;
            }
        }
        return *max_element(arr.begin(),arr.end());
    }
};