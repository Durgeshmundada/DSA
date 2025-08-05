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
    ListNode* partition(ListNode* head, int k) {
        if(!head||!head->next){return head;}
        ListNode* dummy = new ListNode(0);
        ListNode* dummy1 = new ListNode(0);
        ListNode* l1=dummy1;
        ListNode* l2=dummy;
        ListNode* temp=head;

        while(temp){
            if(temp->val>=k){
                l1->next=temp;
                l1=temp;
            }
            else{
                l2->next=temp;
                l2=temp;
            }
            temp=temp->next;
            l1->next = nullptr;

        }
        l2->next=dummy1->next;
        return dummy->next;
    }
};