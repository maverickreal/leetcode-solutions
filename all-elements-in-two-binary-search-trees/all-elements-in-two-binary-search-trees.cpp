class Solution {
public:
#define tn TreeNode
    void func(tn* rt, vector<int>& v) {
        if (!rt)
            return;
        func(rt->left, v);
        v.push_back(rt->val);
        func(rt->right, v);
    }
    vector<int> getAllElements(TreeNode* a, TreeNode* b) {
        vector<int>x, y;
        func(a, x), func(b, y);
        vector<int>res(x.size() + y.size());
        int i = 0, j = 0, k = 0;
        for (;k < res.size() && j < y.size() && i < x.size();++k)
            res[k] = x[i] < y[j] ? x[i++] : y[j++];
        while (i < x.size())
            res[k++] = x[i++];
        while (j < y.size())
            res[k++] = y[j++];
        return res;
    }
};