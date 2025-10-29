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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
       unordered_map<int, int> inMap; // to store inorder value -> index
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;
        int preIndex=0;
        return helper(preorder, inMap, preIndex, 0, inorder.size() - 1);
    }
    TreeNode* helper(vector<int>& preorder, unordered_map<int, int>& inMap, int& preIndex, int inStart, int inEnd){
        if(inStart>inEnd){
            return nullptr;
        }
        int val=preorder[preIndex++];
        TreeNode* root = new TreeNode(val);
        int pos=inMap[val];
        root->left=helper(preorder,inMap,preIndex,inStart,pos-1);
        root->right=helper(preorder,inMap,preIndex,pos+1,inEnd);
    return root;

    }

};