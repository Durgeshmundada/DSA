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
    vector<int> largestValues(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> result1;
        levelOrderRec(root,0,result);
        for(int i=0;i<result.size();i++){
            int x=INT_MIN;
            for(auto j:result[i]){
             x=max(x,j);
            }
            result1.push_back(x);
        }
        return result1;
    }
  void levelOrderRec(TreeNode* root, int level, vector<vector<int>>& res) {
    // Base case
    if (root == nullptr) return;

    // Add a new level to the result if needed
    if (res.size() <= level)
        res.push_back({});
  
    // Add current node's data to its corresponding level
    res[level].push_back(root->val);

    // Recur for left and right children
    levelOrderRec(root->left, level + 1, res);
    levelOrderRec(root->right, level + 1, res);
}

};