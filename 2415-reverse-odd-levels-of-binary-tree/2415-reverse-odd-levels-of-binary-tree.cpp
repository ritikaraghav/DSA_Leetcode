class Solution {
public:
    void solve(TreeNode* leftNode, TreeNode* rightNode, int level) {
        if (leftNode == nullptr || rightNode == nullptr)
            return;

        if (level % 2 == 1)
            swap(leftNode->val, rightNode->val);

        solve(leftNode->left, rightNode->right, level + 1);
        solve(leftNode->right, rightNode->left, level + 1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if (root == nullptr)
            return root;

        solve(root->left, root->right, 1);
        return root;
    }
};