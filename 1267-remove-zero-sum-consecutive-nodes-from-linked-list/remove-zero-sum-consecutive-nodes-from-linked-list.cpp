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
    ListNode* removeZeroSumSublists(ListNode* head) {
        
        ListNode* temp=head;
        vector<int> check;
        while(temp!=nullptr){
            check.push_back(temp->val);
            temp=temp->next;
        }
        for(int i=0;i<check.size();i++){
            int sum=0;
            int x=-1;
            for(int j=i;j<check.size();j++){
                sum+=check[j];
                if(sum==0){
                    x=j;
                    break;
                }
            }
            if(x!=-1){
                for(int k=i;k<=x;k++){
                    check[k]=1001;
                }
                i=x;
            }
        }
        ListNode dummy(0);
    ListNode* tail = &dummy;
    for (int v : check) {
        if (v != 1001) {
            tail->next = new ListNode(v);
            tail = tail->next;
        }
    }
    return dummy.next;
    
    }
};