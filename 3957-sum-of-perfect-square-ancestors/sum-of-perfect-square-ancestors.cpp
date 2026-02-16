class Solution {
public:
    int timer=0;
    vector<int> tin;
    vector<int> tout;
    vector<vector<int>> graph;
    vector<int> squareFree;
    void generateSquareFree(int n){
        squareFree.resize(n+1);
        for(int i=0;i<=n;i++){
            squareFree[i]=i;
        }
        for(int i=1;i<=n;i++){
            if(squareFree[i]!=i) continue;
            int j = 2;
            while(true){
                long long value = i * j * j;
                if(value > n) break;
                squareFree[i*j*j] = squareFree[i];
                j++;
            }
        }
    }
    void dfs(int node,int par){
        tin[node] = timer++;
        for(auto it:graph[node]){
            if(it==par) continue;
            dfs(it,node);
        }
        tout[node] = timer;
    }
    long long merge(int left,int mid,int right,vector<int>& num){
        long long ans = 0;
        int n1 = mid - left + 1;
        int n2 = right - mid;
        vector<int> l(n1);
        vector<int> r(n2);
        for(int i=0;i<n1;i++){
            l[i] = num[left+i];
        }
        for(int j=0;j<n2;j++){
            r[j] = num[mid+1+j];
        }
        int i=0,j=0;
        int k = left;
        while(i<n1 && j<n2){
            if(l[i] < r[j]){
                num[k] = l[i];
                i++;
            }else{
                ans += (n1 - i);
                num[k] = r[j];
                j++;
            }
            k++;
        }
        while(i<n1){
            num[k] = l[i];
            i++;
            k++;
        }
        while(j<n2){
            num[k] = r[j];
            j++;
            k++;
        }
        return ans;
    }
    long long mergeSort(int left,int right,vector<int>& num){
        if(left >= right) return 0;
        int mid = (left+right)/2;
        long long ans = 0;
        ans += mergeSort(left,mid,num);
        ans += mergeSort(mid+1,right,num);
        ans += merge(left,mid,right,num);
        return ans;
    }
    long long helper(vector<vector<int>>& arr){
        vector<int> num;
        sort(arr.begin(),arr.end());
        for(auto it:arr){
            num.push_back(it[1]);
        }
        int n = num.size();
        return mergeSort(0,n-1,num);
    }
    long long sumOfAncestors(int n, vector<vector<int>>& edges, vector<int>& nums) {
        int maxi = *max_element(nums.begin(),nums.end());
        generateSquareFree(maxi);
        tin.resize(n);
        tout.resize(n);
        graph.resize(n,{});
        for(auto it:edges){
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        dfs(0,0);
        unordered_map<int,vector<vector<int>>> umap;
        for(int i=0;i<n;i++){
            int key = squareFree[nums[i]];
            vector<int> value = {tin[i],tout[i]};
            umap[key].push_back(value);
        }
        long long ans = 0;
        for(auto it:umap){
            ans += helper(it.second);
        }
        return ans;
    }
};