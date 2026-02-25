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
    vector<string> ans;
    void helper(TreeNode* root,string part){
        if(root == NULL){
            return ;
        }
        string nextPart = part + to_string(root->val);
        if(root->left == NULL && root->right==NULL){
            ans.push_back(nextPart);
        }
        helper(root->left,nextPart);
        helper(root->right,nextPart);
    }
    int sumNumbers(TreeNode* root) {
        helper(root,"");
        int res = 0;
        for(auto it:ans){
            res += stoi(it);
        }
        return res;
    }
};