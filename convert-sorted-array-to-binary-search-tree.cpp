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
    TreeNode *func(vector<int> &v, int i, int j)

{

	int mid = (i + j) / 2;

	TreeNode *tn = new TreeNode;

	tn->val = v[mid];

	if (i == j)

		return tn;

	if (mid > i)

		tn->left = func(v, i, mid - 1);

	if (mid < j)

		tn->right = func(v, mid + 1, j);

	return tn;

}
    TreeNode* sortedArrayToBST(vector<int>& v) {
        if (!v.size())

	return nullptr;

return func(v, 0, v.size() - 1);
    }
};