class Solution {
public:
    vector<vector<string>> ans;
    map<string, int> mp;
    string begin;
    void dfs(string word, vector<string> s) {
        if (word == begin) {
            ans.push_back(s);
            return;
        }
        int level = mp[word];
        for (int i = 0; i < word.size(); i++) {
            char original = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++) {
                word[i] = ch;
                if (mp.find(word) != mp.end() && mp[word] == level - 1) {
                    s.push_back(word);
                    dfs(word, s);
                    s.pop_back();
                }
            }
            word[i] = original;
        }
    }
    vector<vector<string>> findLadders(string beginWord, string endWord,vector<string>& wordList) {
        queue<string> q;
        begin = beginWord;
        set<string> st;
        for(auto it:wordList){
            st.insert(it);
        }
        q.push(beginWord);
        mp[beginWord] = 1;
        st.erase(beginWord);
        while (!q.empty()) {
            string word = q.front();
            if (word == endWord)
                break;
            int level = mp[word];
            q.pop();
            for (int i = 0; i < beginWord.size(); i++) {
                char original = word[i];
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    word[i] = ch;
                    if (st.find(word) != st.end()) {
                        q.push(word);
                        st.erase(word);
                        mp[word] = level + 1;
                    }
                }
                word[i] = original;
            }
        }
        if (mp.find(endWord) != mp.end()) {
            vector<string> s;
            s.push_back(endWord);
            dfs(endWord, s);
        }
        for(int i=0;i<ans.size();i++){
            reverse(ans[i].begin(),ans[i].end());
        }
        return ans;
    }
};