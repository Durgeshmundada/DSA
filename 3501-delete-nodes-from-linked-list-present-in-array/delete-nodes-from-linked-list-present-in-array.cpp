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
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int,int> um;
        for(int i=0;i<nums.size();i++){
            um[nums[i]]++;
        }
        ListNode* temp=new ListNode(0);
        ListNode* pre=temp;
        pre->next=head; 
        ListNode* curr=head;
        while(curr!=nullptr){
            if(um[curr->val]!=0){
                pre->next=curr->next;
                curr=pre->next;
            }
            else{
                pre=pre->next;
                curr=curr->next;
            }
        }
        return temp->next;
    }
};