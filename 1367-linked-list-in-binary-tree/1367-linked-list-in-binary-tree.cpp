/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
private:
    bool check(ListNode *head, TreeNode* root){
        if(root->val!=head->val){
            return false;
        }
        if(!head->next){
            return true;
        }
        bool left=false;
        bool right=false;
        if(root->left && head->next && head->next->val==root->left->val){
            left=check(head->next,root->left);
        }
        if(root->right && head->next && head->next->val==root->right->val){
            right=check(head->next,root->right);
        }
        return left||right;
        
        
       
    }
public:
    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root){
            return false;
        }
        if(root->val==head->val){
            if(check(head,root)){
                return true;
            }

        }
        return isSubPath(head,root->left)||isSubPath(head,root->right);
       
    }
};