class Solution {
#define tn TreeNode
    int res = 0;
    pair<int, int> func(tn* rt) {
        if (!rt->left && !rt->right)
            return { 0,0 };
        int l = rt->left ? func(rt->left).second + 1 : 0, r = rt->right ? func(rt->right).first + 1 : 0;
        //cout << l << ' ' << r << '\n';
        res = max(res, max(l, r));
        return { l,r };
    }
public:
    int longestZigZag(TreeNode* rt) {
        func(rt);
        return res;
    }
};//[1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]