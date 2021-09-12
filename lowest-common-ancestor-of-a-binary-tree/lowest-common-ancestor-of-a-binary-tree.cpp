class Solution {
#define tn TreeNode
public:
    bool func(tn* rt, tn* nd, vector<tn*>& v) {
        if (!rt)
            return false;
        v.push_back(rt);
        if (rt == nd)
            return true;
        if (func(rt->left, nd, v) || func(rt->right, nd, v))
            return true;
        v.pop_back();
        return false;
    }
    TreeNode* lowestCommonAncestor(TreeNode* rt, TreeNode* p, TreeNode* q) {
        vector<tn*>vp, vq;
        func(rt, p, vp);
        func(rt, q, vq);
        int i = 0;
        while (++i < min(vp.size(), vq.size()) && vp[i] == vq[i]);
        return vp[i - 1];
    }
};