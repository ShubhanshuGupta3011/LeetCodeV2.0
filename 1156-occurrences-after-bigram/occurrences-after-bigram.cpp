class Solution {
public:
    vector<string> findOcurrences(string text, string first, string second) {
        vector<string> all;
        string empty="";
        string part=empty;
        for(auto it:text){
            if(it==' '){
                all.push_back(part);
                part=empty;
            }else{
                part+=it;
            }
        }
        all.push_back(part);
        vector<string> res;
        for(int i=2;i<all.size();i++){
            if(all[i-2]==first  && all[i-1]==second){
                res.push_back(all[i]);
            }
        }
        return res;
    }
};