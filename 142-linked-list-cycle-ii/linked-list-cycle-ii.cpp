/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
class Solution {

public:
 
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int t=-1;
        if(head==nullptr){
            return head;
        }
        
        
        while(fast!=nullptr && fast->next!=nullptr ){
           slow=slow->next;
            fast=fast->next->next;
           if(fast==slow){
            t=0;
            break;
           }       
        } 
        
        if(t==0){
            
            while(fast->next!=slow){
            fast=fast->next;
            t++;
        }
        t++;
        fast=head;
        slow=head;
        for(int i=0;i<t;i++){
            fast=fast->next;
        }
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        
   return slow;
        }return nullptr;
    }
};