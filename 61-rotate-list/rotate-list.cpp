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
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next){
            return head;
        }
        ListNode* temp=head;
        int count=0;
        while(temp){
            count++;
            temp=temp->next;
        }
        
            k=k%count;
        
        for(int i=0;i<k;i++){
            ListNode* temp=head;
            ListNode* temp1=nullptr;
            while(temp->next!=nullptr){
                temp1=temp;
                temp=temp->next;
            }

            temp1->next=nullptr;
            temp->next=head;
            head=temp;
        }
        return head;
    }
};