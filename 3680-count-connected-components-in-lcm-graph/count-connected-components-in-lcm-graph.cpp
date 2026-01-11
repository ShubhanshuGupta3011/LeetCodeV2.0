class Solution {
public:
    long long Threshold ;
    map<int,int> divisor;
    map<int,int> getValueFromIndex;
    vector<int> parent;
    int findParent(int a){
        if(a==parent[a]) return a;
        return parent[a] = findParent(parent[a]);
    }
    void unioned(int a,int b){
        a=findParent(a);
        b=findParent(b);
        parent[b]=a;
    }
    long long gcd(long long a,long long b){
        if(a%b==0) return b;
        return gcd(b,a%b);
    }
    long long lcm(long long a,long long b){
        long long hcf = gcd(a,b);
        return (a/hcf)*(b);
    }
    void helper(int value,int index){
        set<int> fact = {1};
        for(int i=1;i<=sqrt(value);i++){
            if(value%i==0){
                fact.insert(i);
                fact.insert(value/i);
            }
        }
        for(auto it:fact){
            if(divisor.find(it) != divisor.end()){
                int beforeIndex = divisor[it];
                int valueBefore = getValueFromIndex[beforeIndex];
                int valueNow = getValueFromIndex[index];
                if(lcm(valueBefore,valueNow) <= Threshold){
                    unioned(beforeIndex,index);
                }
            }else{
                divisor[it]=index;
            }
        }
    }
    int Component(){
        set<int> st;
        for(int i=0;i<parent.size();i++){
            st.insert(findParent(i));
        }
        return st.size();
    }
    int countComponents(vector<int>& nums, int threshold) {
        Threshold = threshold;
        sort(nums.begin(),nums.end());
        int ans1=0;
        while(nums.size()){
            if(nums.back() <= threshold) break;
            nums.pop_back();
            ans1++;
        }
        if(nums.size() == 0) return ans1;
        if(nums[0] == 1) return 1+ans1;
        for(int i=0;i<nums.size();i++){
            getValueFromIndex[i] = nums[i];
            parent.push_back(i);
        }
        for(int i=0;i<nums.size();i++){
            helper(nums[i],i);
        }
        return ans1+Component();
    }
};