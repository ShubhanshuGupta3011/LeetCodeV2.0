class Solution {
public:
    vector<int> ft;
    void update(int i,int diff){
        while(i<ft.size()){
            ft[i]+=diff;
            i+=(i&-i);
        }
    }
    int getSum(int i){
        if(!i) return 0;
        return ft[i]+getSum(i&(i-1));
    }
    int helper(vector<int>& rating){
        ft.resize(100001,0);
        int n=rating.size();
        vector<int> countSmallerOnLeft(n);
        vector<int> countBiggerOnLeft(n);
        for(int i=0;i<n;i++){
            int smaller = getSum(rating[i]-1);
            countSmallerOnLeft[i] = smaller;
            int bigger = getSum(100000) - getSum(rating[i]);
            countBiggerOnLeft[i] = bigger;
            update(rating[i],1);
        }
        int ans=0;
        for(int k=n-1;k>=0;k--){
            for(int j=k-1;j>=0;j--){
                if(rating[j] == rating[k]) continue;
                if(rating[j] < rating[k]){
                    ans += countSmallerOnLeft[j];
                }else{
                    ans += countBiggerOnLeft[j];
                }
            }
        }
        return ans;
    }
    int numTeams(vector<int>& rating) {
        return helper(rating);
    }
};