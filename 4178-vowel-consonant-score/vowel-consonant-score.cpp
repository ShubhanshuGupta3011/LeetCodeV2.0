class Solution {
public:
    int vowelConsonantScore(string s) {
        set<char> st = {'a','e','i','o','u'};
        set<int> st2 ;
        for(char ch='a';ch<='z';ch++){
            if(!st2.count(ch)){
                st2.insert(ch);
            }
        }
        int v=0,c=0;
        for(auto it:s){
            if(st.count(it)){
                v++;
            }else if(st2.count(it)){
                c++;
            }
        }
        if(c==0) return 0;
        return v/c;
    }
};