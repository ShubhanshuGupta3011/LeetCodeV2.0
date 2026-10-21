class RangeFreqQuery {
public:
    unordered_map<int,vector<int>> umap;
    RangeFreqQuery(vector<int>& arr) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            umap[arr[i]].push_back(i);
        }
    }
    int getIndex(vector<int>& arr,int index){
        int low = 0;
        int high = arr.size()-1;
        int ans = -1;
        while(low<=high){
            int mid = (low + high)/2;
            if(arr[mid] > index){
                high = mid - 1;
            }else{
                ans = mid;
                low = mid + 1;
            }
        }
        return ans;
    }
    int query(int left, int right, int value) {
        if(!umap.count(value)) return 0;
        int l = getIndex(umap[value],left-1);
        int r = getIndex(umap[value],right);
        return r-l;
    }
};

/**
 * Your RangeFreqQuery object will be instantiated and called as such:
 * RangeFreqQuery* obj = new RangeFreqQuery(arr);
 * int param_1 = obj->query(left,right,value);
 */