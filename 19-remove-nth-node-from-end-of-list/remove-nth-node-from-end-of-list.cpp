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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* temp=head;
        ListNode* temp1;
        int count=1;
        while(temp->next!=nullptr){
            temp=temp->next;
            count++;
        }
         if(n == count) {
            ListNode* newHead = head->next;
            head->next = nullptr;
            return newHead;
        }
        temp=head;
        for(int i=1;i<count-n;i++){
            temp=temp->next;
        }
        temp1=temp->next;
       
        temp->next=temp1->next;
        temp1->next=nullptr;
      
        return head;
    }
};