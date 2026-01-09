class Solution {
public:
    unordered_map<TreeNode*, int> um;

    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        level(0, root);
        return res(root, um[root]);
    }

    void level(int l, TreeNode* root) {
        if (root == nullptr) return;

        level(l + 1, root->left);
        level(l + 1, root->right);

        if (root->left && root->right) {
            um[root] = max(um[root->left], um[root->right]);
        }
        else if (root->left) {
            um[root] = um[root->left];
        }
        else if (root->right) {
            um[root] = um[root->right];
        }
        else {
            um[root] = l; 
        }
    }

    TreeNode* res(TreeNode* root, int x) {
        if (root == nullptr) return nullptr;
        if (!root->left && !root->right) {
            return root;
        }

        if (root->left && root->right) {
            if (um[root->left] == x && um[root->right] == x) {
                return root;
            }
        }

        if (root->left && um[root->left] == x) {
            return res(root->left, x);
        }

        return res(root->right, x);
    }
};
