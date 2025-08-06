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
    void reorderList(ListNode* head) {
       if(!head || !head->next){
        return;
       }
        deque<ListNode*> temp;
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast){
            temp.push_back(fast);
            fast=fast->next;
        }
        ListNode* extra;
        
        extra = temp.front();
        temp.pop_front();

        
        head=extra;
        int i=1;
        while(!temp.empty()){
            if(i==1){
               extra->next= temp.back();
               extra=extra->next;
               temp.pop_back();
               i=0;
            }
            else{
                extra->next=temp.front();
                extra=extra->next;
               temp.pop_front();
               i=1;
            }            
        }  
        extra->next=nullptr;
    }
};