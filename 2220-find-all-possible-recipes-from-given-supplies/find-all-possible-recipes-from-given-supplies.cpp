class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        int n=recipes.size();
        map<string,vector<string>> mp;
        map<string,int> indegree;
        for(int i=0;i<n;i++){
            for(auto it:ingredients[i]){
                mp[it].push_back(recipes[i]);
            }
            indegree[recipes[i]]+=ingredients[i].size();
        }
        queue<string> q;
        for(auto it:supplies){
            if(indegree.find(it) != indegree.end()) continue;
            q.push(it);
        }
        set<string> made;
        while(q.size()){
            string curr = q.front();
            made.insert(curr);
            q.pop();
            for(auto it:mp[curr]){
                if(indegree[it] == 1){
                    q.push(it);
                }
                indegree[it]--;
            }
        }
        vector<string> res;
        for(auto it:recipes){
            if(made.count(it)){
                res.push_back(it);
            }
        }
        return res;
    }
};