class Solution {
#define tn TreeNode
public:
    int k;
    int res = -1;
    int func(tn* rt, int pre = 0) {
        if (!rt)
            return pre;
        int l = func(rt->left, pre);
        if (l == -1)
            return -1;
        if (l + 1 == k) {
            res = rt->val;
            return -1;
        }
        int r = func(rt->right, l + 1);
        if (r == -1)
            return -1;
        return r;
    }
    int kthSmallest(TreeNode* rt, int K) {
        k=K;
        func(rt);
        return res;
    }
};