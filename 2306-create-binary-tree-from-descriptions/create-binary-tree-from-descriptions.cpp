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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> um;
        unordered_map<int,int> root;
        TreeNode* result;
        for(int i=0;i<descriptions.size();i++){
             TreeNode* t;
              TreeNode* l;
            if(um.find(descriptions[i][0])==um.end()){
                 t=new TreeNode(descriptions[i][0]);
            }
            else{
                t=um[descriptions[i][0]];
            }
            if(um.find(descriptions[i][1])==um.end()){
               l=new TreeNode(descriptions[i][1]);
            }
            else{
              l=um[descriptions[i][1]];
            }
            if(descriptions[i][2]){
               t->left=l; 
            }
            else{
                t->right=l;
            }
            root[descriptions[i][1]]=descriptions[i][0];
            um[descriptions[i][0]]=t;
            um[descriptions[i][1]]=l;
        }
        int x=descriptions[0][0];
        while(root.find(x)!=root.end()) {
            x=root[x];
            cout<<x;
        }
        result=um[x];
        return result;
    }
};