class Solution {
public:
    int solve(string s){
        vector<int> arr(s.size(),1);
        for(int i=1;i<s.size();i++){
            if(s[i]==s[i-1]){
                arr[i]=1+arr[i-1];
            }
        }
        return *max_element(arr.begin(),arr.end());
    }
    int helper(char x,char y,string s){
        int ans=0,key=0;
        map<int,int> mp,empty;
        mp[key]=-1;
        for(int i=0;i<s.size();i++){
            if(s[i]!=x && s[i]!=y){
                mp = empty;
                key=0;
                mp[key]=i;
            }else if(s[i]==x){
                key++;
            }else{
                key--;
            }
            if(mp.find(key)!=mp.end()){
                ans=max(ans,i-mp[key]);
            }else{
                mp[key]=i;
            }
        }
        return ans;
    }
    int helping(string s){
        int counta=0,countb=0,countc=0;
        int ans=0;
        map<pair<pair<int,int>,int> ,int> mp;
        mp[{{0,0},0}] = -1;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a') counta++;
            if(s[i]=='b') countb++;
            if(s[i]=='c') countc++;
            int mini = min(counta,min(countb,countc));
            int a=counta-mini;
            int b=countb-mini;
            int c=countc-mini;
            if(mp.find({{a,b},c}) != mp.end()){
                ans=max(ans,i-mp[{{a,b},c}]);
            }else{
                mp[{{a,b},c}] = i;
            }
        }
        return ans;

    }
    int longestBalanced(string s) {
        int ans = helper('a','b',s);
        ans = max(ans,helper('b','c',s));
        ans = max(ans,helper('c','a',s));
        ans=max(ans,solve(s));
        ans=max(ans,helping(s));
        return ans;
    }
};