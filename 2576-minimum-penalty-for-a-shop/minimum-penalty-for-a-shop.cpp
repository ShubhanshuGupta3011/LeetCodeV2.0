class Solution {
public:
    int bestClosingTime(string s) {
        int n=s.size();
        int totalY=0,totalN=0;
        for(auto it:s){
            totalY+=(it=='Y');
            totalN+=(it=='N');
        }
        if(totalY==n) return n;
        if(totalN==n) return 0;
        int penalty=INT_MAX;
        int currY=0,currN=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(currN+totalY-currY < penalty){
                penalty = currN+totalY-currY;
                ans=i;
            }
            currY+=(s[i]=='Y');
            currN+=(s[i]=='N');
        }
        if(totalN < penalty){
            ans=n;
            penalty = totalN; 
        }
        return ans;
    }
};