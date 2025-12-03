/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    map<pair<int,int>,vector<int>> mp;
    void helper(TreeNode* root,int level,int pos){
        if(root == NULL) return ;
        mp[{pos,level}].push_back(root->val);
        helper(root->left,level+1,pos-1);
        helper(root->right,level+1,pos+1);
        return ;
    }
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        helper(root,0,0);
        int mini=0;
        int maxi=0;
        for(auto it:mp){
            mini=min(mini,it.first.first);
            maxi=max(maxi,it.first.first);
        }
        vector<vector<int>> ans(maxi-mini+1);
        for(auto it:mp){
            int key = it.first.first - mini;
            sort(it.second.begin(),it.second.end());
            for(auto itt:it.second){
                ans[key].push_back(itt);
            }
        }
        return ans;
    }
};