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
    int gcd(int a,int b){
        return b==0?a:gcd(b,a%b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp1=head;
        while(head){
            temp=head->next;
            if(temp==NULL){
                break;
            }
            ListNode* head1=new ListNode(gcd(head->val,temp->val));
            head->next=head1;
            head1->next=temp;
            
            
            
            
            
            
            head=temp;
            
        }

        return temp1;
        
    }
};