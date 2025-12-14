class Solution {
public:
    vector<int> ft;
    vector<int> myArr;
    int getSum(int node){
        int ans=0;
        while(node){
            ans+=ft[node];
            node-=(node & (-node));
        }
        return ans;
    }
    void update(int node,int value){
        // cout<<"before node value is "<<node<<" = "<<myArr[node]<<endl;
        int diff = value - myArr[node];
        myArr[node]=value;
        // cout<<"before node value is "<<node<<" = "<<myArr[node]<<endl;
        while(node<ft.size()){
            ft[node]+=diff;
            node+=(node & (-node));
        }
    }
    vector<int> minDeletions(string s, vector<vector<int>>& queries) {
        int n=s.size();
        vector<int> ans;
        if(n==1){
            for(auto it:queries){
                if(it[0]==2){
                    ans.push_back(0);
                }
            }
            return ans;
        }
        myArr.resize(n,0);
        ft.resize(n,0);
        for(int i=1;i<n;i++){
            if(s[i]==s[i-1]){
                update(i,1);
            }
        }

        for(auto it:queries){
            if(it[0]==1){
                int index=it[1];
                s[index] = (s[index]=='A') ? 'B' : 'A';
                int left=index-1;
                int right=index+1;
                // cout<<"left = "<<left<<" right = "<<right<<endl;
                if(left>=0){
                    if(s[left]==s[index]){
                        update(index,1);
                    }else{
                        update(index,0);
                    }
                }
                if(right<n){
                    if(s[index]==s[right]){
                        update(right,1);
                    }else{
                        update(right,0);
                    }
                }
            }else{
                int left=it[1];
                int right=it[2];
                // cout<<"s = "<<s<<endl;
                // for(auto it:myArr){
                //     cout<<it<<",";
                // }
                // cout<<endl;
                // for(auto it:ft){
                //     cout<<it<<",";
                // }
                // cout<<endl;
                ans.push_back(getSum(right)-getSum(left));
            }
        }
        return ans;
    }
};