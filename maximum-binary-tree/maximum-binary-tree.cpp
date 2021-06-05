class Solution {
#define tn TreeNode
    //unordered_mao<int, int>ump;
    int sz;
    tn* func(int i, int j, const vector<int>& v) {
        if (i > j)
            return nullptr;
        int mx = i;
        for (int k = i;k <= j;++k)
            if (v[k] > v[mx])
                mx = k;
        tn* res = new tn(v[mx]);
        res->left = func(i, mx - 1, v);
        res->right = func(mx + 1, j, v);
        return res;
    }
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& v) {
        sz = v.size();
        //for (int i = 0;i < sz;++i)
          //  ump[v[i]] = i;
        return func(0, sz - 1, v);
    }
};