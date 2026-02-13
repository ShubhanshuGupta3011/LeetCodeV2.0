class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> arr(5,1);
        while(n){
            vector<int> arr2(5);
            arr2[0] = arr[0]+arr[1]+arr[2]+arr[3]+arr[4];
            arr2[1] = arr[1]+arr[2]+arr[3]+arr[4];
            arr2[2] = arr[2]+arr[3]+arr[4];
            arr2[3] = arr[3]+arr[4];
            arr2[4] = arr[4];
            arr = arr2;
            n--;
        }
        return arr[0];
    }
};