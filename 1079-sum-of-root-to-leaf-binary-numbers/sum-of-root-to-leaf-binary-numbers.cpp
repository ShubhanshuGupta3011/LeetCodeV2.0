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
    int ans = 0;
    void helper(TreeNode* root,int value){
        if(root == NULL) return ;
        if(root->left == NULL && root->right == NULL){
            int currValue = root->val;
            ans += 2*value;
            ans += currValue;
            return ;
        }
        helper(root->left,2*value + root->val);
        helper(root->right,2*value + root->val);
    }
    int sumRootToLeaf(TreeNode* root) {
        helper(root,0);
        return ans;
    }
};