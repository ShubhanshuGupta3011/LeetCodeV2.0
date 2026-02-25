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
    int res = 0;
    void helper(TreeNode* root,int part){
        if(root == NULL){
            return ;
        }
        int nextPart = 10 * part + (root->val);
        if(root->left == NULL && root->right==NULL){
            res += nextPart;
        }
        helper(root->left,nextPart);
        helper(root->right,nextPart);
    }
    int sumNumbers(TreeNode* root) {
        helper(root,0);
        return res;
    }
};