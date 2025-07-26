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
    ListNode* reverseKGroup(ListNode* head, int k) {
         if (!head || k <= 1) return head;

        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* temp = dummy;

        ListNode* countNode = head;
        int count = 0;
        while (countNode) {
            count++;
            countNode = countNode->next;
        }

        while (count >= k) {
            ListNode* prev = nullptr;
            ListNode* curr = temp->next;
            ListNode* next = nullptr;
            ListNode* groupHead = curr; 

           
            for (int i = 0; i < k; i++) {
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }

            
            temp->next = prev;
            groupHead->next = curr;

           
            temp = groupHead;

            count -= k;
        }

        return dummy->next;
    }
};