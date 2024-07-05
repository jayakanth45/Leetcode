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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
            int prev=head->val;
        head=head->next;
        vector<int> ans;
        int count=2;
        while(head->next){
            if(head->val>prev && head->val>head->next->val){
                ans.push_back(count);
            }
            if(head->val<prev && head->val<head->next->val){
                ans.push_back(count);
            }
            prev=head->val;
            head=head->next;
            
            
            count++;
        }
        if(ans.size()<2){
            return {-1,-1};
        }
        int max1=ans[ans.size()-1]-ans[0];
        int min1=INT_MAX;
        for(int i=1;i<ans.size();i++){
            min1=min(min1,ans[i]-ans[i-1]);
        }
        return {min1,max1};
    
        
        
        
    }
};