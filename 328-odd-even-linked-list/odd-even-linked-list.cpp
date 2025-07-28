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
    ListNode* oddEvenList(ListNode* head) {
        if(head==nullptr || head->next==nullptr){return head;}
      ListNode* temp=head;
      ListNode* temp1=head->next;
      ListNode* temp2=temp1;
      ListNode* temp3;
      
      int count=0;
      int count1=0;
      while(temp!=nullptr && temp1!=nullptr){
        if(count%2==0){
            temp->next=temp1->next;
            if(temp->next==nullptr){
                break;
            }
            temp=temp->next;
            count++;
            
        }
        else{
            temp1->next=temp->next;
            temp1=temp1->next;
            count++;
        }
        }

        temp->next=temp2;
  return head;
    }
};