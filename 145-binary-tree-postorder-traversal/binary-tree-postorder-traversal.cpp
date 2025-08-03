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
        inorderTraversal1(root->left,temp);
        
        inorderTraversal1(root->right,temp);
        temp.push_back(root->val);
        }
    vector<int> postorderTraversal(TreeNode* root) {
       vector<int> temp;
       inorderTraversal1(root,temp);
        return temp; 
    }
};