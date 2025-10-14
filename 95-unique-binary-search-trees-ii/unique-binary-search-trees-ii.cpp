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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0) return {}; 
        return makebst(1, n);
    }
    vector<TreeNode*> makebst(int start,int end){
        vector<TreeNode*> result;
        if(start>end){
            result.push_back(nullptr);
            return result;
        }
        for(int i=start;i<=end;i++){
            vector<TreeNode*> left=makebst(start,i-1);
            vector<TreeNode*> right=makebst(i+1,end);
            for(TreeNode* l:left){
                for(TreeNode* r:right){
                     TreeNode* node = new TreeNode(i);
                    node->left = l;
                    node->right = r;
                    result.push_back(node);
                }
            }
        }
        return result;
    }
};