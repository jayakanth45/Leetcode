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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
       int count=1;
        ListNode* temp=head;
        ListNode* temp1=head;
        if(head->next==NULL && n==1)
        {head=NULL;
         return head;
        }
        while(count<n){
            temp=temp->next;
            count++;
        }
        if(temp->next==NULL){
            head=head->next;
            return head;
        }
        
        while(head->next&& temp->next){
            
            if(!temp->next->next){
                head->next=head->next->next;
                return temp1;
            }
            
            
            
            
            head=head->next;
            temp=temp->next;
        }
        return temp1;
    }
};