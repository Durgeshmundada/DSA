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
    int pairSum(ListNode* head) {
        vector<int> sum;
        ListNode* temp=head;
        while(temp){
            sum.push_back(temp->val);
            temp=temp->next;
        }
        int result=INT_MIN;
        for(int i=0;i<sum.size()/2;i++){
            result=max(result,sum[i]+sum[sum.size()-1-i]);
        }
        return result;
    }
};