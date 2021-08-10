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
    bool isSameTree(TreeNode* l, TreeNode* r) {
        if (l == NULL and r == NULL)

	return true;

if (l == NULL or r == NULL)

	return false;

if (l->val != r->val)

	return false;

return isSameTree(l->left, r->left) and isSameTree(l->right, r->right);
    }
};