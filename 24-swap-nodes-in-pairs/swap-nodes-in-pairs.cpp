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
    ListNode* swapPairs(ListNode* head) {
        if(!head || !head->next){
            return head;
        }
        ListNode* temp=head;
        
        ListNode* temp2 = new ListNode(0);
       
        temp2->next=head;
        head=head->next;
        while( temp!=nullptr && temp->next!=nullptr ){
            temp2->next=temp->next;
            temp->next=temp->next->next;
            temp2=temp2->next;
            temp2->next=temp;
            temp2=temp2->next;
            temp=temp->next;
           
        }
        return head;
    }
};