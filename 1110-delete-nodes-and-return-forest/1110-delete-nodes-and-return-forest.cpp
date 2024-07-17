class Solution {
public:
    TreeNode* solve(TreeNode* node,vector<TreeNode*>& ans,unordered_set<int>& st){
        if(node==NULL){
            return NULL;
        }
        node->left = solve(node->left,ans,st);
        node->right = solve(node->right,ans,st);
        if(st.find(node->val)!=st.end()){
            if(node->left){
                ans.push_back(node->left);
            }
            if(node->right){
                ans.push_back(node->right);
            }
            return NULL;
        }else{
            return node;
        }
    }
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> ans;
        unordered_set<int> st(to_delete.begin(),to_delete.end());
        solve(root,ans,st);
        if(st.find(root->val)==st.end()){
            ans.push_back(root);
        }
        return ans;
    }
};