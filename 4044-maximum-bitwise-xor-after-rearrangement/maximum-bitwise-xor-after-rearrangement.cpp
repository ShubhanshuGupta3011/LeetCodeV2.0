class Solution {
public:
    string maximumXor(string s, string t) {
        int count0 = 0;
        int count1 = 0;
        for(auto it:t){
            count0 += (it=='0');
            count1 += (it!='0');
        }
        string ans = "";
        for(auto it:s){
            if(it=='1'){
                if(count0){
                    ans+="1";
                    count0--;
                }else{
                    ans+="0";
                    count1--;
                }
            }else{
                if(count1){
                    ans+="1";
                    count1--;
                }else{
                    ans+="0";
                    count0--;
                }
            }
        }
        return ans;
    }
};