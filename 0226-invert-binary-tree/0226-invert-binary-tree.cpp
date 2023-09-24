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

    void swap_lr(TreeNode* root)
    {
        TreeNode* tmp;

        tmp = root -> left;
        root -> left = root -> right;
        root -> right = tmp;
    }

    void recur_invert(TreeNode* root) 
    {
        if (root == nullptr)
            return;

        recur_invert(root -> left);
        recur_invert(root -> right);
        swap_lr(root);
    }

    TreeNode* invertTree(TreeNode* root) {
        
        recur_invert(root);
        return root;
    }
};