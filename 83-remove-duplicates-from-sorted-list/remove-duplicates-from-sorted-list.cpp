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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=head;
        ListNode* temp1=nullptr;
        //ListNode* temp3=nullptr;
        if(head==nullptr || head->next==nullptr){
            return head;
        }
        while(temp!=nullptr){
            temp1=temp;
            if(temp->next==nullptr){
            return head;
        }
            temp=temp->next;
            if(temp->val==temp1->val){
                if(temp->next==nullptr){
                    temp1->next=nullptr;
                }
                else{
                    temp1->next=temp->next;
                    temp=temp1;
                }
            }
           
        }
        
        return head;
    }
};