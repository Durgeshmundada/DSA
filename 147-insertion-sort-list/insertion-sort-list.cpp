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
    ListNode* insertionSortList(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* temp=head->next;
        ListNode* dummy=new ListNode(0);
        ListNode* sorth=head;
        ListNode* sort=head;
        ListNode* sortt=dummy;
        
         sort->next=nullptr;
         sortt->next=head;
        while(temp){
            ListNode* prev=temp;
            temp=temp->next;
            sortt=dummy;
            while(sortt->next && sortt->next->val<prev->val ){
                
                sortt=sortt->next;
            }
            
            prev->next=sortt->next;
            sortt->next=prev;
            
        }
        return dummy->next;
    }
};