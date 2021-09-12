class Solution {
#define tn TreeNode
public:
    int res = 0;
    void func(tn* rt, int mx = INT_MIN) {
        if (!rt)
            return;
        if (rt->val >= mx) {
            ++res;
            //cout<<mx<<' '<<rt->val<<'\n';
            mx = rt->val;
        }
        func(rt->left, mx), func(rt->right, mx);
    }
    int goodNodes(TreeNode* rt) {
        func(rt);
        return res;
    }
};