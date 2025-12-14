class Solution {
public:
    int countVowel(string s){
        set<char> st={'a','e','i','o','u'};
        int ans=0;
        for(auto it:s){
            ans+=st.count(it);
        }
        return ans;
    }
    string reverseWords(string s) {
        s+=' ';
        vector<string> arr;
        string part="";
        int firstTime = -1;
        for(auto it:s){
            if(it==' '){
                int countVowels = countVowel(part);
                cout<<"part = "<<part<<" countVowels = "<<countVowels<<endl;
                if(countVowels == firstTime){
                    reverse(part.begin(),part.end());
                }
                if(firstTime == -1){
                    firstTime = countVowels;
                }
                arr.push_back(part);
                part="";
            }else{
                part+=it;
            }
        }
        string ans=arr[0];
        for(int i=1;i<arr.size();i++){
            ans+=' ';
            ans+=arr[i];
        }
        return ans;
    }
};