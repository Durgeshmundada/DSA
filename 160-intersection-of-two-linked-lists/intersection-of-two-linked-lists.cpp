/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
         ListNode* a = headA;
        ListNode* b = headB;

        // Traverse both lists
        while (a != b) {
            // Move to the next node, or switch to the other list's head
            a = (a == nullptr) ? headB : a->next;
            b = (b == nullptr) ? headA : b->next;
        }

        // Either intersection node or nullptr
        return a;
    }
};
/* 
my solution -
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    ListNode* temp=headA;
    ListNode* temp2=headA;
    

    
        while(headB!=nullptr){
            while(temp2!=nullptr){
                if(temp2==headB){
                    
                    return temp2;
                }
                temp2=temp2->next;
            }
            headB=headB->next;
            //temp=temp->next;
            temp2=temp;
        }
        return nullptr;
    }
};*/