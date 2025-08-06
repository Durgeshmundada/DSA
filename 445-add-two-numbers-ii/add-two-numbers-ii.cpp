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
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = nullptr;
        while (head) {
            ListNode* next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        stack<int> first;
        stack<int> second;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1){
            first.push(temp1->val);
            temp1=temp1->next;
        }
        while(temp2){
            second.push(temp2->val);
            temp2=temp2->next;
        } 
        ListNode *s1=new ListNode(0);
         ListNode *temp=s1;
         
       int carry=0;
        while (!first.empty() || !second.empty() || carry) {
            int sum = carry;

            if (!first.empty()) {
                sum += first.top();
                first.pop();
            }

            if (!second.empty()) {
                sum += second.top();
                second.pop();
            }

            ListNode* s = new ListNode(sum % 10);
            temp->next = s;
            temp = temp->next;
            carry = sum / 10;
        }
        ListNode* result = reverseList(s1->next);
        delete s1;
        return result;  
    }
};