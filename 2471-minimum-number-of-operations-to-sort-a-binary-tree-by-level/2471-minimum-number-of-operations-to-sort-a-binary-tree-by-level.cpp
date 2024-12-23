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
   int fun(vector<int> &v)
    {
        vector<pair<int,int>> vp ;
        int n=v.size() ;
        for(int i=0 ; i<n ; i++)  vp.push_back({v[i] , i}) ;
        sort(vp.begin() , vp.end()) ;
        int ct=0 ;

        for(int i=0 ; i<n ; i++)
        {
            if(i != vp[i].second)
            {
                ct++ ;
                swap( vp[vp[i].second] , vp[i] ) ;
                i-- ;
            }
        }
        return ct ;
    }
    int minimumOperations(TreeNode* root) {
        int ans=0 ;
        queue<TreeNode*> q ;
        q.push(root) ;
        q.push(NULL) ;
        
        while(!q.empty())
        {
            int sz = q.size() ;
            
            while(sz--)
            {
                TreeNode *cur = q.front() ;
                q.pop() ;
                if(cur == NULL)
                {
                    vector<int> v ;
                    queue<TreeNode*> temp ;
                    while(!q.empty())
                    {
                        temp.push(q.front()) ;
                        v.push_back(q.front()->val) ;
                        q.pop() ;
                    }
                    ans += fun(v) ;
                    q=temp ;
                    if(q.size() > 0) q.push(NULL) ;
                }
                else
                {
                    if(cur->left)  q.push(cur->left) ;
                    if(cur->right)  q.push(cur->right) ;
                }
            }
        }
        return ans ;
    }
};