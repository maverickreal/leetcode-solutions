/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
#define tn TreeNode
class Solution {
public:
    void alpha(tn *rt, stack<tn *> &s, int x)

{

	s.push(rt);

	if (rt->val == x)

		return;

	if (rt->val < x)

		return alpha(rt->right, s, x);

	return alpha(rt->left, s, x);

}
    TreeNode* lowestCommonAncestor(TreeNode* rt, TreeNode* a, TreeNode* b) {
        if (rt == NULL or (rt->left == NULL and rt->right == NULL))

	return rt;

stack<tn *> s1, s2;

alpha(rt, s1, a->val);

alpha(rt, s2, b->val);

while (s1.size() != s2.size())

	(s1.size() < s2.size() ? s2 : s1).pop();

tn *res = rt;

while (!s1.empty())

{

	tn *x = s1.top(), *y = s2.top();

	s1.pop();

	s2.pop();

	if (x->val == y->val)

	{

		res = x;

		break;

	}

}

return res;
    }
};