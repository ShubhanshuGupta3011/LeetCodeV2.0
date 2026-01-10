class Fancy {
public:
    Fancy() {
        
    }
    int mod=1e9+7;
    int multi(int a,int b){
        return (1ll*a*b)%mod;
    }
    int add(int a,int b){
        return (a+b)%mod;
    }
    int power(int x,int n){
        if(n<2) return n?x:1;
        int f = power(x,n%2);
        int s = power(multi(x,x),n/2);
        return multi(f,s);
    }
    int inverse(int x){
        return power(x,mod-2);
    }
    vector<int> arr;
    vector<int> addChunk;
    vector<int> multiChunk;
    int bucket = 320;
    void append(int val) {
        int index = arr.size();
        if(index % bucket == 0){
            addChunk.push_back(0);
            multiChunk.push_back(1);
        }else{
            val-=addChunk[index/bucket];
            int inv = inverse(multiChunk[index/bucket]);
            val = multi(val,inv);
            val = add(val,mod);
        }
        arr.push_back(val);
    }
    
    void addAll(int inc) {
        for(int i=0;i<addChunk.size();i++){
            addChunk[i]=add(addChunk[i],inc);
        }
    }
    
    void multAll(int m) {
        for(int i=0;i<multiChunk.size();i++){
            multiChunk[i]=multi(multiChunk[i],m);
            addChunk[i]=multi(addChunk[i],m);
        }
    }
    
    int getIndex(int idx) {
        if(idx >= arr.size()) return -1;
        int fact = multiChunk[idx/bucket];
        int adding = addChunk[idx/bucket];
        return add(adding,multi(fact,arr[idx]));
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */