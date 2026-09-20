class Solution {
public:
    int upper(int i,int low,int high,vector<vector<int>>& intervals){
        int mid,ans=i;
        while(low<=high){
            mid = (low+high)/2;
            if(intervals[mid][0] > intervals[i][1]){
                high = mid - 1;
            }else{
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {
        long long ans = 0;
        int n = intervals.size();
        sort(intervals.begin(),intervals.end());
        for(int i=0;i<n;i++){
            int j = upper(i,i+1,n-1,intervals);
            ans += (j-i);
        }
        return ans;
    }
};