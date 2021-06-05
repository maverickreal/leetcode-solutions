class Solution {
public:
#define tn TreeNode
    int func(tn* rt, int add = 0) {
        if (!rt)
            return 0;
        int orig = rt->val, rit = func(rt->right, add);
        rt->val += rit + add;
        return func(rt->left, add + orig + rit) + orig + rit;
    }
    TreeNode* bstToGst(TreeNode* rt) {
        func(rt);
        return rt;
    }
};