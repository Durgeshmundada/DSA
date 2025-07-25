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
    ListNode* middleNode(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp1=head;
        while(temp1->next!=nullptr && temp1->next->next != nullptr){
            temp=temp->next;
            temp1=temp1->next->next;
        }
        if(temp1->next!=nullptr){
             temp=temp->next;
        }
        return temp;
    }
};