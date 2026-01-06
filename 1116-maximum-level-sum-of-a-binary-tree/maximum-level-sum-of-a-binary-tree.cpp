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
    map<int,long long> map;
    void solve(int level,TreeNode* root){
        if(root == NULL) return ;
        int value = root->val;
        map[level]+=value;
        solve(level+1,root->left);
        solve(level+1,root->right);
    }
    int maxLevelSum(TreeNode* root) {
        solve(1,root);
        long long maxi=-1e18;
        for(auto it:map){
            maxi=max(maxi,it.second);
        }
        for(auto it:map){
            if(it.second == maxi){
                return it.first;
            }
        }
        return -1;
    }
};