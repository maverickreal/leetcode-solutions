class Solution {
#define tn Treenode::
public:
    int rangeSumBST(TreeNode* rt, int l, int r) {
        if (!rt) return 0;
        if (rt->val < l)
            return rangeSumBST(rt->right, l, r);
        if (rt->val > r)
            return rangeSumBST(rt->left, l, r);
        if (rt->val == l)
            return l + rangeSumBST(rt->right, l, r);
        if (rt->val == r)
            return rangeSumBST(rt->left, l, r) + r;
        return rt->val + rangeSumBST(rt->right, l, r) + rangeSumBST(rt->left, l, r);
    }
};