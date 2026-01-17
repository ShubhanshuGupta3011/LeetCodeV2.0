class Solution {
public:
    vector<int> getLeftSmaller(vector<int>& heights,int n){
        vector<int> ans(n,-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() && heights[i]<heights[st.top()]){
                st.pop();
            }
            if(st.size()){
                ans[i]=st.top();
            }
            st.push(i);
        }
        return ans;
    }
    vector<int> getRightSmaller(vector<int>& heights,int n){
        vector<int> ans(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(st.size() && heights[i] < heights[st.top()]){
                ans[st.top()]=i;
                st.pop();
            }
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        // vector<int> leftSmaller = getLeftSmaller(heights,n);
        // vector<int> rightSmaller = getRightSmaller(heights,n);
        int ans=0;
        // for(int i=0;i<n;i++){
        //     ans = max(ans,heights[i] * (rightSmaller[i]-leftSmaller[i]-1));
        // }
        stack<pair<int,int>> st;
        for(int i=0;i<n;i++){

            while(st.size()){
                int prevIndex = st.top().first;
                int left = st.top().second;
                int right = i;
                if(heights[prevIndex] > heights[i]){
                    ans = max(ans, heights[prevIndex] * (right - left - 1));
                    st.pop();
                }else{
                    break;
                }
            }

            if(st.empty()){
                st.push({i,-1});
            }else{
                int prevIndex = st.top().first;
                st.push({i,prevIndex});
            }
        }

        while(st.size()){
            int prevIndex = st.top().first;
            int left = st.top().second;
            int right = n;
            ans = max(ans, heights[prevIndex] * (right - left - 1));
            st.pop();
        }


        return ans;
    }
};