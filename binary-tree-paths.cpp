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
    void func(tn *rt, vector<string> &v, string s = "")

{

	for (auto i : to_string(rt->val))

		s.push_back(i);

	if (rt->left == NULL and rt->right == NULL)

	{

		v.push_back(s);

		return;

	}

	s.append("->");

	if (rt->left != NULL)

		func(rt->left, v, s);

	if (rt->right != NULL)

		func(rt->right, v, s);

}
    vector<string> binaryTreePaths(TreeNode* rt) {
        vector<string> v;

if (rt == NULL)

	return v;

if (rt->left == NULL and rt->right == NULL)

{

	v.push_back(to_string(rt->val));

	return v;

}

func(rt, v);

return v;
    }
};