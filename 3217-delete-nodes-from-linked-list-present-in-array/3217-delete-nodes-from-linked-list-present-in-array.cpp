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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> um;
        for(auto x:nums){
            um[x]=1;
        }
       ListNode *temp=new ListNode(-1);
        ListNode* temp1=temp;
        while(head){
            if(um.find(head->val)==um.end()){
                 ListNode *k=new ListNode(head->val);
                temp->next=k;
                temp=temp->next;
                
            }
            
            
            
            head=head->next;
        }
        
        
        
        
        return temp1->next;
        
        
    }
};