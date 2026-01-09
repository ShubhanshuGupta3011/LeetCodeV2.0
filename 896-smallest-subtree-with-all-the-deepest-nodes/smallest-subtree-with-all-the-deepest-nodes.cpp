/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left),
 * right(right) {}
 * };
 */
class Solution {
public:
    int maxDepth;
    int dfs(TreeNode* root) {
        if (!root)
            return 0;
        int left = 1 + dfs(root->left);
        int right = 1 + dfs(root->right);
        return max(left, right);
    }
    TreeNode* findNode(TreeNode* root, int depth) {
        if (!root)
            return NULL;
        if (depth == maxDepth - 1) {
            if (root->left && root->right)
                return root;
            return root->left ? root->left : root->right;
        }

        auto left = findNode(root->left, depth + 1);
        auto right = findNode(root->right, depth + 1);
        if (left && right) {
            return root;
        }
        return left ? left : right;
    }
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        int maxDepth = dfs(root);
        this->maxDepth = maxDepth;
        if (maxDepth == 1)
            return root;
        auto node = findNode(root, 1);
        return node;
    }
};