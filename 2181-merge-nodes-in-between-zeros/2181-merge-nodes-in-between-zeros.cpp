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
    ListNode* mergeNodes(ListNode* head) {
        ListNode* head1=new ListNode(0);
    
        ListNode* temp=head1;
        head=head->next;
     
        int sum=0;
        while(head){
            sum=sum+head->val;
            if(head->val==0){
                if(sum!=0){
                ListNode* d = new ListNode(sum);
                head1->next=d;
             
                sum=0;
                head1=head1->next;
                }
            }
            head=head->next;
            
        }
        return temp->next;
        
    }
};