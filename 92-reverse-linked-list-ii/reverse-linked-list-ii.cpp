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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
              ListNode* temp=head;
        ListNode* dummy=new ListNode(0);
        dummy->next=head;
        ListNode* temp1=dummy;
        ListNode* temp2=head;
        
        if(right==0 || right==1 || right==left){
            return head;
        }
       
        for(int i=1;i<left;i++){
            temp1=temp;
            temp=temp->next;
        }
        if(right-1==left){
            int tempy=temp->val;
            temp1=temp->next;
            temp->val=temp1->val;
            temp1->val=tempy;
            return head;
        }
        if(right-2==left){
            int tempy=temp->val;
            temp1=temp->next->next;
            temp->val=temp1->val;
            temp1->val=tempy;
            return head;
        }
        temp2=temp;
        for(int i=left-1;i<right;i++){
            
            temp2=temp2->next;
        }
          ListNode* prev = temp1;
        ListNode* curr = temp;
        
        while (curr != temp2) {
            ListNode* nextTemp = curr->next;
            curr->next = prev;               
            prev = curr;                     
            curr = nextTemp;                
        }
        
        temp1->next=prev;
        temp->next=temp2;
       if(left==1){
        head=prev;
       }
        
return head;
    }
};