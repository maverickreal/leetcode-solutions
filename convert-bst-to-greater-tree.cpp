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
    void getter(tn *rt, vector<tn *> *v)

{

	if (rt == NULL)

		return;

    getter(rt->right, v);

	v->push_back(rt);

    getter(rt->left, v);

}
    TreeNode* convertBST(TreeNode* rt) {
        if (rt == NULL or (rt->left == NULL and rt->right == NULL))

	return rt;

vector<tn *> *v = new vector<tn *>;

getter(rt, v);

for (int i = 1; i < v->size(); ++i)

	(*v)[i]->val += (*v)[i - 1]->val;

delete v;

return rt;
    }
};