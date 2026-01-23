class Solution {
public:
    int n;
    int stoneGameVI(vector<int>& aliceValues, vector<int>& bobValues) {
        /*
        3,2,1
        10,4,6
        10,3,7
        */
        n = aliceValues.size();
        int bobTotal = 0;
        vector<vector<int>> arr;
        for(int i=0;i<n;i++){
            arr.push_back({aliceValues[i]+bobValues[i],aliceValues[i],bobValues[i]});
            bobTotal += bobValues[i];
        }
        sort(arr.begin(),arr.end());
        for(auto it:arr){
            cout<<it[0]<<","<<it[1]<<","<<it[2]<<endl;
        }
        int AliceTotal = 0;
        while(arr.size()){
            auto it = arr.back();
            arr.pop_back();
            if(arr.size()){
                arr.pop_back();
            }
            AliceTotal += it[0];
        }
        cout<<"AliceTotal = "<<AliceTotal<<" bobTotal = "<<bobTotal<<endl;
        if(AliceTotal == bobTotal) return 0;
        if(AliceTotal > bobTotal) return 1;
        return -1;
    }
};