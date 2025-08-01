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
void inorderTraversal1(TreeNode* root,vector<int>& temp) {
    if(root==nullptr){return;}
        
        temp.push_back(root->val);
        inorderTraversal1(root->left,temp);
        inorderTraversal1(root->right,temp);
        }
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> temp;
       inorderTraversal1(root,temp);
        return temp;
    }
};