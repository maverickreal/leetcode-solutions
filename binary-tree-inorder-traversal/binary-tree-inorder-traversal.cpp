class Solution {
#define tn TreeNode
public:
    vector<int>res;
    void func(tn* rt) {
        if (rt->left)
            func(rt->left);
        res.push_back(rt->val);
        if (rt->right)
            func(rt->right);
    }
    vector<int> inorderTraversal(TreeNode* rt) {
        if (rt)
            func(rt);
        return res;
    }
};