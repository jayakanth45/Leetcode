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
    int level(TreeNode* root){
        if(root==NULL) return 0;
        return max(level(root->left), level(root->right))+1;
    }
    void f(TreeNode* root, int &ans){
        if(root==NULL) return;
        f(root->left, ans);
        f(root->right, ans);
        int diameter = level(root->left)+level(root->right);
        ans = max(ans, diameter);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        f(root, ans);
        return ans;
    }
};