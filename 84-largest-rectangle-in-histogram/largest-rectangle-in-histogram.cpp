class Solution {
public:
    void avoidDuplicated(stack<pair<int,int>>& st,vector<int>& heights,int i,int& ans){
        while(st.size()){
            int prevIndex = st.top().first;
            int left = st.top().second;
            int right = i;
            if(i==heights.size() || heights[prevIndex] > heights[i]){
                ans = max(ans, heights[prevIndex] * (right - left - 1));
                st.pop();
            }else{
                break;
            }
        }
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        int ans=0;
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){
            avoidDuplicated(st,heights,i,ans);
            int left = st.empty() ? -1 : st.top().first;
            st.push({i,left});
        }
        avoidDuplicated(st,heights,n,ans);
        return ans;
    }
};