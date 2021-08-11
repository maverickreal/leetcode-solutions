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
#define tn TreeNode
class Solution {
public:
    void func(tn *rt, bool ch, int &n)

{

	if (rt->left == NULL and rt->right == NULL and ch){

		n += rt->val;
        return;
        }
		if (rt->left != NULL)

			func(rt->left, true, n);

		if (rt->right != NULL)

			func(rt->right, false, n);


}
    int sumOfLeftLeaves(TreeNode* rt) {
        if (rt == NULL or (rt->left == NULL and rt->right == NULL))

	return 0;

int n=0;
if(rt->left!=NULL)
    func(rt->left, true, n);
if(rt->right!=NULL)
    func(rt->right, false, n);

return n;
    }
};