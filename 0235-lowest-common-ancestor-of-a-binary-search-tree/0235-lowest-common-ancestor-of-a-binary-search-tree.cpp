/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        if (root == p || root == q)
            return root;
        else if (root == nullptr)
            return nullptr;
        
        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if (left == right)
            return left;
        else if (left != nullptr && right == nullptr)
            return left;
        else if (left == nullptr && right != nullptr)
            return right;
        else
            return root;
    }
};