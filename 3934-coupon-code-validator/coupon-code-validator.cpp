class Solution {
public:
    vector<string> validateCoupons(vector<string>& code, vector<string>& businessLine, vector<bool>& isActive) {
        set<char> st;
        set<string> buss = {"electronics", "grocery", "pharmacy", "restaurant"};
        for(char ch='a';ch<='z';ch++){
            st.insert(ch);
        }
        for(char ch='A';ch<='Z';ch++){
            st.insert(ch);
        }
        for(char ch='0';ch<='9';ch++){
            st.insert(ch);
        }
        st.insert('_');
        map<string,vector<string>> mp;
        int n=code.size();
        for(int i=0;i<n;i++){
            if(isActive[i]){
                if(buss.count(businessLine[i])){
                    int flag=1;
                    for(auto it:code[i]){
                        if(!st.count(it)){
                            flag=0;
                            break;
                        }
                    }
                    if(flag && code[i].size()){
                        mp[businessLine[i]].push_back(code[i]);
                    }
                }
            }
        }
        vector<string> ans;
        for(auto it:mp){
            if(it.second.size()){
                sort(it.second.begin(),it.second.end());
                for(auto itt:it.second){
                    ans.push_back(itt);
                }
            }
        }
        return ans;
    }
};