class Solution {
public:
    vector<int> getIds(vector<string>& event){
        vector<int> ans;
        for(auto it:event){
            ans.push_back(stoi(it.substr(2)));
        }
        return ans;
    }
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        sort(events.begin(), events.end(), [](const vector<string> &a, const vector<string> &b){
            int ta = stoi(a[1]);
            int tb = stoi(b[1]);
            if (ta != tb) 
                return ta < tb; 
            return a[0] > b[0];  
        });
        for(auto it:events){
            cout<<it[0]<<" "<<it[1]<<" "<<it[2]<<endl;
        }
        vector<int> ans(numberOfUsers,0);
        set<pair<int,int>> st;
        multiset<int> offline;
        for(auto it:events){
            if(it[0]=="OFFLINE"){
                int timestamp = stoi(it[1]);
                int id = stoi(it[2]);
                timestamp+=60;
                st.insert({timestamp,id});
                offline.insert(id);
            }else{
                if(it[2]=="ALL"){
                    for(int i=0;i<numberOfUsers;i++){
                        ans[i]++;
                    }
                    continue;
                }
                int currTimestamp=stoi(it[1]);
                while(!st.empty()){
                    auto top = *st.begin();
                    cout<<top.first<<" "<<top.second<<" "<<endl;
                    if(top.first <= currTimestamp){
                        st.erase(top);
                        offline.erase(offline.find(top.second));
                    }else{
                        break;
                    }
                }
                if(it[2]=="HERE"){
                    for(int i=0;i<numberOfUsers;i++){
                        if(!offline.count(i)){
                            ans[i]++;
                        }
                    }
                    continue;
                }
                string event = it[2];
                vector<string> currIds;
                string part="";
                for(auto it:event){
                    if(it==' '){
                        currIds.push_back(part);
                        part="";
                    }else{
                        part+=it;
                    }
                }
                if(part.size()){
                    currIds.push_back(part);
                }
                vector<int> ids = getIds(currIds);
                while(ids.size()){
                    ans[ids.back()]++;
                    ids.pop_back();
                }
            }
        }
        return ans;
    }
};