class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        vector<int> odd(26,0),even(26,0);
        for(int i=0;i<n;i++){
            if(i&1){
                odd[s1[i]-'a']++;
            }else{
                even[s1[i]-'a']++;
            }
        }
        for(int i=0;i<n;i++){
            if(i&1){
                odd[s2[i]-'a']--;
            }else{
                even[s2[i]-'a']--;
            }
        }
        for(auto it:odd){
            if(it) return 0;
        }
        for(auto it:even){
            if(it) return 0;
        }
        return 1;
    }


};