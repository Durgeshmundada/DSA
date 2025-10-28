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
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        levelOrderRec(root,0,res);
        return res;
    }
    void levelOrderRec(Node* root, int level, vector<vector<int>>& res) {
    // Base case
    if (root == nullptr) return;

    // Add a new level to the result if needed
    if (res.size() <= level)
        res.push_back({});
  
    // Add current node's data to its corresponding level
    res[level].push_back(root->val);

    // Recur for left and right children
    for(auto temp:root->children)
    levelOrderRec(temp, level + 1, res);
}
};