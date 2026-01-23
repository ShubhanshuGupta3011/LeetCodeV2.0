class RandomizedCollection {
public:
    RandomizedCollection() {
        
    }
    
    int index = 0;
    unordered_map<int,set<int>> getIndex;
    vector<int> arr;
    bool insert(int val) {
        bool res = getIndex.count(val);
        getIndex[val].insert(index);
        index++;
        arr.push_back(val);
        return !res;
    }
    
    bool remove(int val) {
        bool res = getIndex.count(val);
        if(res){

            if(val == arr.back()){
                getIndex[val].erase(arr.size()-1);
                arr.pop_back();
                index--;
                if(getIndex[val].size() == 0){
                    getIndex.erase(val);
                }
            }else{
                int firstIndexOfVal = *getIndex[val].begin();
                int lastIndex = arr.size()-1;
                int lastvalue = arr.back();

                getIndex[val].erase(firstIndexOfVal);
                getIndex[lastvalue].erase(lastIndex);

                swap(arr[firstIndexOfVal],arr[lastIndex]);
                arr.pop_back();
                index--;

                getIndex[lastvalue].insert(firstIndexOfVal);
                if(getIndex[val].size() == 0){
                    getIndex.erase(val);
                }
            }
        }
        return res;
    }
    
    int getRandom() {
        int n = arr.size();
        int randomIndex = rand() % n;
        return arr[randomIndex];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection* obj = new RandomizedCollection();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */