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
        vector<int> leftSmaller = getLeftSmaller(heights,n);
        vector<int> rightSmaller = getRightSmaller(heights,n);
        int ans=0;
        for(int i=0;i<n;i++){
            ans = max(ans,heights[i] * (rightSmaller[i]-leftSmaller[i]-1));
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> arr(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = matrix[i][j]-'0';
            }
        }
        for(int i=1;i<n;i++){
            for(int j=0;j<m;j++){
                arr[i][j] = arr[i][j] * (arr[i][j]+arr[i-1][j]);
            }
        }
        int ans=0;
        for(auto it:arr){
            ans=max(ans,largestRectangleArea(it));
        }
        return ans;
    }
};