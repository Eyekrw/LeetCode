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

    int count_node(TreeNode* root)
    {
        if (root == nullptr)
            return 0;

        int cnt_l = count_node(root -> left);
        if (cnt_l != -1) cnt_l++;
        int cnt_r = count_node(root -> right);
        if (cnt_r != -1) cnt_r++;

        if (abs(cnt_l - cnt_r) <= 1)
            return max(cnt_l, cnt_r);
        else
            return -1;
    }

    bool isBalanced(TreeNode* root) {
        
        if (count_node(root) == -1)
            return false;
        return true;
    }
};