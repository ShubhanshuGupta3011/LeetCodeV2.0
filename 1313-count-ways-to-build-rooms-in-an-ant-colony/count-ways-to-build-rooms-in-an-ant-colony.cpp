class Solution {
public:
    vector<int> fact;
    vector<int> invFact;
    vector<int> dp;
    vector<int> subTree;
    vector<vector<int>> graph;
    int mod = 1e9 + 7;
    int multi(int a, int b) { return (1ll * a * b) % mod; }
    int power(int x, int n) {
        if(n<2) return n ? x : 1;
        return multi(power(x,n%2) , power(multi(x,x),n/2));
    }
    int inverse(int x){
        return power(x,mod-2);
    }
    void dfs(int node){
        dp[node]=1;
        subTree[node]=0;
        for(auto child:graph[node]){
            dfs(child);
            dp[node] = multi(dp[child],dp[node]);
            subTree[node] += subTree[child];
        }
        int ways = fact[subTree[node]];
        for(auto child:graph[node]){
            ways = multi(ways,invFact[subTree[child]]);
        }
        dp[node] = multi(dp[node],ways);
        subTree[node]++;
    }
    int waysToBuildRooms(vector<int>& prevRoom) {
        int n = prevRoom.size();
        fact.resize(n+1,1);
        invFact.resize(n+1,1);
        dp.resize(n,0);
        subTree.resize(n,0);
        graph.resize(n,{});
        for(int i=1;i<=n;i++) fact[i] = multi(fact[i-1],i);
        invFact[n] = inverse(fact[n]);
        for(int i=n-1;i>=0;i--) invFact[i] = multi(invFact[i+1],i+1);
        for(int i=1;i<n;i++) graph[prevRoom[i]].push_back(i);
        dfs(0);
        return dp[0];
    }
};