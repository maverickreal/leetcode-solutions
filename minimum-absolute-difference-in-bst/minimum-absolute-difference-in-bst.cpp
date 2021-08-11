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
    void func(tn *rt, multiset<int> *st)

{

	st->insert(rt->val);

	if (rt->left != NULL)

		func(rt->left, st);

	if (rt->right != NULL)

		func(rt->right, st);

}
    int getMinimumDifference(TreeNode* rt) {
        multiset<int> *st = new multiset<int>;

func(rt, st);

vector<int> v(st->begin(), st->end());

delete st;

int res = INT_MAX;

for (auto it = v.begin() + 1; it < v.end(); ++it)

{

	res = min(res, abs(*it - *(it - 1)));

	if (!res)

		break;

}

return res;
    }
};