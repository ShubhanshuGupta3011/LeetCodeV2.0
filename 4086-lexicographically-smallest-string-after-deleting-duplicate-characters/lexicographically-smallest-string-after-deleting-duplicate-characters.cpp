class Solution {
public:
    string lexSmallestAfterDeletion(string s) {
        /*
        a a c b
        */
        vector<int> freqTotal(26,0);
        for(auto it:s){
            freqTotal[it-'a']++;
        }
        stack<char> st;
        vector<int> freqCurr(26,0);
        for(int i=0;i<s.size();i++){
            while(st.size() && st.top()>s[i]){
                if(freqTotal[st.top()-'a']){
                    freqCurr[st.top()-'a']--;
                    st.pop();
                }else{
                    if(freqCurr[st.top()-'a']>1){
                        freqCurr[st.top()-'a']--;
                        st.pop();
                    }else{
                        break;
                    }
                }
            }
            st.push(s[i]);
            freqCurr[s[i]-'a']++;
            freqTotal[s[i]-'a']--;
        }
        while(st.size()){
            char last = st.top();
            if(freqCurr[last-'a']>1){
                freqCurr[last-'a']--;
                st.pop();
            }else{
                break;
            }
        }
        string ans="";
        while(st.size()){
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};