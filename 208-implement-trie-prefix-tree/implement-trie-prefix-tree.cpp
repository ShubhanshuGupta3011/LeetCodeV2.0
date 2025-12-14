class Trie {
public:
    map<int,int> startWith;
    map<int,int> start;
    int mod=1e9+7;
    int add(int a,int b){
        return (a+b)%mod;
    }
    int multi(int a,int b){
        return (1ll*a*b)%mod;
    }
    Trie() {
        
    }
    
    void insert(string word) {
        int key=0;
        for(int i=0;i<word.size();i++){
            key=multi(key,31);
            key=add(key,word[i]-'a'+1);
            startWith[key]=1;
        }
        start[key]=1;
    }
    
    bool search(string word) {
        int key=0;
        for(int i=0;i<word.size();i++){
            key=multi(key,31);
            key=add(key,word[i]-'a'+1);
        }
        return start.find(key)!=start.end();
    }
    
    bool startsWith(string word) {
        int key=0;
        for(int i=0;i<word.size();i++){
            key=multi(key,31);
            key=add(key,word[i]-'a'+1);
        }
        return startWith.find(key)!=startWith.end();
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */