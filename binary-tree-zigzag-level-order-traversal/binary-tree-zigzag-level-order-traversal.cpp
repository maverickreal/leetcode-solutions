class Solution {
public:
#define tn TreeNode
    unordered_map<int, vector<int>>ump;
    void func(tn* rt, int lev = 0) {
        if (!rt) return;
        ump[lev].push_back(rt->val);
        func(rt->left, lev + 1), func(rt->right, lev + 1);
    }
    vector<vector<int>> zigzagLevelOrder(TreeNode* rt) {
        func(rt);
        vector<vector<int>>res(ump.size());
        for (int i = 0;i < ump.size();++i) {
            res[i] = ump[i];
            if (i & 1)
                reverse(res[i].begin(), res[i].end());
        }
        return res;
    }
};