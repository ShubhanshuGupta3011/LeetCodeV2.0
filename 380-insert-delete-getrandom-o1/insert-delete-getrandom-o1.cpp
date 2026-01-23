class RandomizedSet {
public:
    RandomizedSet() {
        
    }
    int index=0;
    unordered_map<int,int> getIndex;
    vector<int> arr;
    bool insert(int val) {
        if(getIndex.count(val)){
            return false;
        }
        getIndex[val] = index;
        index++;
        arr.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(getIndex.count(val)){
            int currIndex = getIndex[val];
            int lastIndex = arr.size()-1;
            int lastValue = arr.back();
            getIndex[lastValue] = currIndex;
            swap(arr[currIndex],arr[lastIndex]);
            arr.pop_back();
            getIndex.erase(val);
            index--;
            return true;
        }
        return false;
    }
    
    int getRandom() {
        int n = arr.size();
        int randomIndex = rand() % n;
        return arr[randomIndex];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */