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
    bool res = true;
    int height(TreeNode* root){
        if(root == NULL) return 0;
        int left = 1+height(root->left);
        int right = 1+height(root->right);
        if(abs(left-right) >= 2){
            res = false;
        }
        return max(left,right);
    }
    bool isBalanced(TreeNode* root) {
        height(root);
        return res;
    }
};