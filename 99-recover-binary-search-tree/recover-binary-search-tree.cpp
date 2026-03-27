/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
TreeNode* first=nullptr;
TreeNode* prev=nullptr;
TreeNode* mid=nullptr;
TreeNode* last=nullptr;
    void recoverTree(TreeNode* root) {
        check(root);
        if(last!=nullptr && first!=nullptr) swap(last->val,first->val);
        else swap(first->val,mid->val);
        return ;
    }
    void check(TreeNode* root){
        if(root==nullptr) return;
        check(root->left);
        if(prev!=nullptr && (prev->val>root->val) ){
            if(first==nullptr){
                first=prev;
                mid=root;
            }
            else{
                last=root;
            }
        }
        prev=root;
        check(root->right);
    }
};