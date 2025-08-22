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
public:vector<string> result;
int i=0;
vector<string> s;
string sh;
    vector<string> binaryTreePaths(TreeNode* root) {
        if(root==nullptr){
            return result;
        }
        sh=sh+"->"+to_string(root->val);
        if(root->left==nullptr && root->right==nullptr){
           s.push_back(sh.substr(2));
           
        }else{
        binaryTreePaths(root->left);
        binaryTreePaths(root->right);}
        for(int i=0;i<(to_string(root->val)).size()+2;i++){
            sh.pop_back();
           }
        return s;
    }
};