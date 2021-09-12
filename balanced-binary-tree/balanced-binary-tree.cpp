class Solution {
#define tn TreeNode
public:
    bool res = true;
    int func(tn* rt) {
        if (!rt)
            return 0;
        int l = func(rt->left);
        if (l == -1)
            return -1;
        int r = func(rt->right);
        if (r == -1)
            return -1;
        if (abs(l - r) > 1) {
            res = false;
            return -1;
        }
        return max(l, r) + 1;
    }
    bool isBalanced(TreeNode* rt) {
        if (!rt)
            return true;
        func(rt);
        return res;
    }
};