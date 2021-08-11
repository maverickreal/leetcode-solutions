class Solution {
public:
#define tn TreeNode
    tn* func(tn* rt, const int& n) {
        if (!rt || rt->val == n)
            return rt;
        tn* res = func(rt->left, n);
        if (!res)
            res = func(rt->right, n);
        return res;
    }
    TreeNode* getTargetCopy(TreeNode* o, TreeNode* c, TreeNode* tar) {
        return func(c, tar->val);
    }
};