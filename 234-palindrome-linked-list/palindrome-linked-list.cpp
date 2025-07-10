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
    bool isPalindrome(ListNode* head) {
       if (head == nullptr || head->next == nullptr) return true;

        ListNode* temp=nullptr;
         ListNode* temp1=nullptr;
        ListNode* fast=head;
        ListNode* slow=head;
        while(fast && fast->next){
                 fast=fast->next->next;
                 temp=slow->next;
                 slow->next=temp1;
                 temp1=slow;
                 slow=temp;
                 

        }
        
        if(fast) {
            
            slow=slow->next;
        }
        
       while (temp1 && slow) {
            if (temp1->val != slow->val)
                return false;
            temp1 = temp1->next;
            slow = slow->next;
        }
         
        return 1;
       
    }
};