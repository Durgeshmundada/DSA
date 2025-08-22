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
int max;
int x;
int countNodes1(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        countNodes1(root->left);
        max=max+1;
        return max;
    }
    int countNodesright(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }
        countNodesright(root->right);
        max=max+1;
        return max;
    }
    int countNodes(TreeNode* root) {  
       if(root==nullptr){
        return 0;
       }
       int left=countNodes1(root->left);
       max=0;
       int right=countNodesright(root->right);
       max=0;
       if(left==right){
        return pow(2,left+1)-1;
       }
      
       return 1+countNodes(root->left)+countNodes(root->right);
    }
};