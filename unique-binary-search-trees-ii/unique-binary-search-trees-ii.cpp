class Solution {
#define tn TreeNode
public:
    vector<TreeNode*> generateTrees(int e, int s = 1) {
        //cout << s << ' ' << e << '\n';
        if (s > e)
            return { nullptr };
        if (s == e)
            return { new tn(s) };
        vector<tn*>res;
        for (int i = s;i <= e;++i) {
            auto l = generateTrees(i - 1, s), r = generateTrees(e, i + 1);
            for (tn* lnd : l) {
                for (tn* rnd : r)
                    res.push_back(new tn(i, lnd, rnd));
            }
        }
        return res;
    }
};