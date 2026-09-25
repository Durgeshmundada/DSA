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
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>>ans;
       vector<int>res;
       check(root,targetSum,res,ans);
       return ans; 
    }
    void check(TreeNode* root, int target , vector<int> res,vector<vector<int>>&ans){
        if(root==nullptr) return;
        target-=root->val;
        res.push_back(root->val);
        if(target==0){
            if(root->left==nullptr && root->right==nullptr){
                ans.push_back(res);
            }
        }
        check(root->left,target,res,ans);
        check(root->right,target,res,ans);
    }
};