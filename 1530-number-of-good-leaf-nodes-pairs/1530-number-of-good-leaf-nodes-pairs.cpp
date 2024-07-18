class Solution {
public:
    vector<int> dfs(TreeNode* root, int distance,int& ans){
        if(root == NULL) return {0};
        if(!root->left && !root->right) return {1};
        vector<int> left = dfs(root->left,distance,ans);
        vector<int> right = dfs(root->right,distance,ans);

        for(int x : left){
            for(int y: right){
                if(x > 0 && y > 0 && x+y <= distance) ans++;
            }
        }
        vector<int> res;
        for(int x: left){
            if(x>0 && x<distance){
                res.push_back(x+1);
            }
        }
        for(int y:right){
            if(y>0 && y< distance){
                res.push_back(y+1);
            }
        }
        return res;
        
    }
    int countPairs(TreeNode* root, int distance) {
        int ans = 0;
        dfs(root,distance,ans);
        return ans;
    }
};