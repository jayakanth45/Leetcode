class Solution {
private:
    string ans = "";
    // lowest common ancester
    TreeNode* LCA(TreeNode* root, int s, int t){
        // if either is found return them
        if(root==NULL || root->val == s || root->val == t){
            return root;
        }
        // look in left & right subtree
        auto l = LCA(root->left,s,t);
        auto r = LCA(root->right,s,t);

        if(l==NULL){
            return r;
        }
        else if(r==NULL){
            return l;
        }
        // lowest common ancester
        // if both l and r for a node is not null then it gotta be the lca 
        else return root;
    }

    void fl(TreeNode* root, int n, string& s){
        if(root==NULL) return;
        if(root->val == n) {
            ans += s;
            return;
        }
        s += "U";
        fl(root->left,n,s);
        fl(root->right,n,s);
        s.pop_back();
    }
    void fr(TreeNode* root, int n, string& s){
        if(root==NULL) return;
        if(root->val == n) {
            ans += s;
            return;
        }
        s += "L";
        fr(root->left,n,s);
        s.back() = 'R';
        fr(root->right,n,s);
        s.pop_back();
    }
public:
    string getDirections(TreeNode* root, int s, int t) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        // get the lowest common ancester of s and t
        TreeNode* lca = LCA(root,s,t);
        string str = "";

        // get the path from lca to s
        fl(lca,s,str);
        // get the path from lca to t
        fr(lca,t,str);

        return ans;
    }
}; //        TC = O(n)            