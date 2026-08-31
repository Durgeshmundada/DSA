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
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        vector<int>res(2,-1);
        vector<int>pos;
        int ma=INT_MIN;
        int mi=INT_MAX;
        ListNode* nex=head->next->next;
        ListNode* curr=head->next;
        ListNode* prev=head;
        int i=0;
        while(nex){
            if(curr->val>prev->val && curr->val>nex->val){
                pos.push_back(i);
            }
            if(curr->val<prev->val && curr->val<nex->val){
                pos.push_back(i);
            }
            i++;
            nex=nex->next;
            curr=curr->next;
            prev=prev->next;
        }
        if(pos.size()<2) return res;
        res[1]=pos[pos.size()-1]-pos[0];
        for(int i=1;i<pos.size();i++){
            mi=min(mi,pos[i]-pos[i-1]);
        }
        res[0]=mi;
        return res;
    }
};