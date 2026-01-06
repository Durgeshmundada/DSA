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
    int maxLevelSum(TreeNode* root) {
        vector<int> sum;
        level(0,root,sum);
        int result=0;
        for(int i=1;i<sum.size();i++){
           if(sum[result]<sum[i]){
            result=i;
           }
        }
        return result+1;
    }
    void level(int l,TreeNode* root,vector<int>& sum){
        if(root==nullptr){
            return;
        }
        if(sum.size()<=l){
            sum.push_back(root->val);
        }
        else{
        sum[l]+=root->val;
        }
        level(l+1,root->left,sum);
        level(l+1,root->right,sum);
        return;
    }
};