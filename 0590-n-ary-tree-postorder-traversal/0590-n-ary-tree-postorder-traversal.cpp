class Solution {
public:
    void traverse (Node* currNode, vector<int>&ans){
        if(currNode == NULL)return;
        for(auto child:currNode->children){
            traverse(child, ans);
        }
        ans.push_back(currNode->val);
    }
    vector<int> postorder(Node* root) {
        vector<int>ans;
        if (root==NULL)return ans;
        traverse(root,ans);
        return ans;
    }
};