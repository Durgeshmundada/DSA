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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inMap; // inorder value -> index
        for (int i = 0; i < inorder.size(); i++)
            inMap[inorder[i]] = i;

        int postIndex = postorder.size() - 1; // start from the end (root of postorder)
        return helper(postorder, inMap, postIndex, 0, inorder.size() - 1);
    }

    TreeNode* helper(vector<int>& postorder, unordered_map<int, int>& inMap,
                     int& postIndex, int inStart, int inEnd) {
        if (inStart > inEnd)
            return nullptr;

        // Get root from postorder
        int val = postorder[postIndex--];
        TreeNode* root = new TreeNode(val);

        // Find the position in inorder
        int pos = inMap[val];

        // Important: build RIGHT first, then LEFT
        root->right = helper(postorder, inMap, postIndex, pos + 1, inEnd);
        root->left  = helper(postorder, inMap, postIndex, inStart, pos - 1);

        return root;
    }
};
