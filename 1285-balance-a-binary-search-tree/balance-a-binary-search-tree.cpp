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
    TreeNode* balanceBST(TreeNode* root) {
       vector<int> result;
       inor(root,result);
        return make(result,0,result.size()-1);
    }
    void inor(TreeNode* root, vector<int>& result){
        if(root==nullptr){
            return;
        }
        inor(root->left,result);
        result.push_back(root->val);
        inor(root->right,result);
    }
    TreeNode* make(vector<int>& result,int left,int right){
        if(left>right){
            return nullptr;
        }
        int mid=left+(right-left)/2;
        TreeNode* root = new TreeNode(result[mid]);
        root->left=make(result,left,mid-1);
        root->right=make(result,mid+1,right);
        return root;
    }
};