class Solution {
public:
#define tn TreeNode
#define pi pair<int,int>
    static bool cmp(const pi& a, const pi& b) {
        return a.first == b.first ? a.second < b.second : a.first < b.first;
    }
    map<int, vector<pi>>mp;
    void func(tn* rt, int r = 0, int b = 0) {
        if (!rt)
            return;
        func(rt->right, r + 1, b + 1);
        func(rt->left, r - 1, b + 1);
        mp[r].push_back({ b,rt->val });
    }
    vector<vector<int>> verticalTraversal(TreeNode* rt) {
        func(rt);
        vector<vector<int>> res;
        for (auto it = mp.begin();it != mp.end();++it) {
            sort(it->second.begin(), it->second.end(), cmp);
            int sz = it->second.size();
            vector<int>tmp(sz);
            for (int i = 0;i < sz;++i)
                tmp[i] = it->second[i].second;
            res.push_back(tmp);
        }
        return res;
    }
};