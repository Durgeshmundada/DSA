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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp=dummy;
        ListNode* temp1=head;
        while(temp1!=nullptr){
            if(temp1->val==val){
                if(temp1==head){
                    head=head->next;
                }
                temp->next=temp1->next;
                temp1=temp->next;
            }
            else{temp=temp1;
            temp1=temp1->next;}
        }
        return head;
    }
};