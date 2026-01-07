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
    int mod=1e9+7;
    long long total;
    long long ans;
    
    long long getMaxProduct(TreeNode* root){
        if(root == NULL) return 0;
        long long leftSum = getMaxProduct(root->left);
        long long rightSum = getMaxProduct(root->right);
        ans = max(ans,1ll*leftSum*(total-leftSum));
        ans = max(ans,1ll*rightSum*(total-rightSum));
        return root->val + leftSum + rightSum;
    }
    long long  getSum(TreeNode* root){
        if(root == NULL) return 0;
        long long left = getSum(root->left);
        long long right = getSum(root->right);
        return root->val + left + right;
    }
    int maxProduct(TreeNode* root) {
        total = getSum(root);
        ans=0;
        getMaxProduct(root);
        return ans%mod;
    }
};