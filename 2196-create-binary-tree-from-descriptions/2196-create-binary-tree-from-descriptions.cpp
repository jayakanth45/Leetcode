
class Solution {
public:
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        int n = descriptions.size();
        unordered_map<int, int> mpt;
        for (int i = 0; i < n; i++) {
            mpt[descriptions[i][0]] = 1;
        }
        for (int i = 0; i < n; i++) {
            mpt[descriptions[i][1]] = 0;
        }

        TreeNode* root = NULL;
        unordered_map<int, TreeNode*> mp;
        for (int i = 0; i < n; i++) {
            if (mpt[descriptions[i][0]] == 1) {
                root = new TreeNode(descriptions[i][0]);
                mp[descriptions[i][0]] = root;
            }
        }       
        for (int i = 0; i < n; i++) {
            if(mp[descriptions[i][0]]){
                if(mp[descriptions[i][1]]){
                    if (descriptions[i][2] == 1) {
                        mp[descriptions[i][0]]->left = mp[descriptions[i][1]];
                    } else {
                        mp[descriptions[i][0]]->right = mp[descriptions[i][1]];
                    }
                }
                else{
                    TreeNode* c = new TreeNode(descriptions[i][1]);
                    if (descriptions[i][2] == 1) {
                        mp[descriptions[i][0]]->left = c;
                    } else {
                        mp[descriptions[i][0]]->right = c;
                    }
                    mp[descriptions[i][1]] = c;
                }
            }
            else{
                TreeNode* p = new TreeNode(descriptions[i][0]);
                if(mp[descriptions[i][1]]){
                    if (descriptions[i][2] == 1) {
                        p->left = mp[descriptions[i][1]];
                    } else {
                        p->right = mp[descriptions[i][1]];
                    }
                }
                else{
                    TreeNode* c = new TreeNode(descriptions[i][1]);
                    if (descriptions[i][2] == 1) {
                        p->left = c;
                    } else {
                        p->right = c;
                    }
                    mp[descriptions[i][1]] = c;
                }
                mp[descriptions[i][0]] = p;
            }
        }

        return root;
    }
};