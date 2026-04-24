class Solution {
public:
    int furthestDistanceFromOrigin(string moves) {
        int r=0,l=0,e=0;
        for(auto it:moves){
            if(it=='L'){
                l++;
            }else if(it=='R'){
                r++;
            }else{
                e++;
            }
        }
        return e+abs(l-r);
    }
};