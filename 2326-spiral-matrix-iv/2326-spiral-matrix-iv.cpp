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
class Solution {
public:
    vector<vector<int>> spiralMatrix(int m, int n, ListNode* head) {
        vector<vector<int>> ans(m,vector<int>(n,-1));
        int i=0,j=0,k=0,p=0,count=0;
        bool flag1=0,flag2=0,flag3=0,flag4=1;
        int temp1=m,temp2=n;
        while(head && count<=m*n && i<m && j<n){
            if(i==p && flag4){
                ans[i][j]=head->val;
                cout<<ans[i][j];
                if(j==n-1)
                    i++;
                else
                j++;
                flag1=1;
                flag4=0;
                p++;
            }
           else if(j==temp2-1 && flag1){
               temp2--;
               ans[i][j]=head->val;
               i++;
               flag2=1;
               flag1=0;
           }
            else if(i==temp1-1 && flag2){
                temp1--;
                ans[i][j]=head->val;
                j--;
                flag2=0;
                flag3=1;
            }
            else if(j==k && flag3){
                k++;
                flag4=1;
                ans[i][j]=head->val;
                i--;
                flag3=0;
            }
           else if(flag1){
                ans[i][j++]=head->val;
               cout<<ans[i][j];
            }
            else if(flag2){
                ans[i++][j]=head->val;
            }
            else if(flag3){
                ans[i][j--]=head->val;
            }
            else if(flag4){
                ans[i--][j]=head->val;
            }
            
            head=head->next;
            count++;
        }
        return ans;
        
        
        
    }
};