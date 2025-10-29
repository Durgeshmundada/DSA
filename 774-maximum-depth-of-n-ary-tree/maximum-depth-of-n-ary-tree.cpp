/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int maxDepth(Node* root) {
        if(root==nullptr){
            return 0;
        }
        int max1=0;
        for(auto i:root->children){
           max1=max(max1,maxDepth(i));
        }
        return max1+1;
    }
};