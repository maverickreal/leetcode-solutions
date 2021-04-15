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
    bool hasPathSum(TreeNode *rt, int tar)

{

	if (!rt)

		return false;

	if (rt->left == NULL and rt->right == NULL)

		return rt->val == tar;

	return hasPathSum(rt->left, tar - rt->val) or hasPathSum(rt->right, tar - rt->val);

}
};