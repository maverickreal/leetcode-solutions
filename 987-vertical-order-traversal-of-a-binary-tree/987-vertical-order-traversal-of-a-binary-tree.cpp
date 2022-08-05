class Solution {
    typedef long long ll;
    typedef pair<ll, TreeNode*> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';

    class tri {
    public:
        ll r, c;
        TreeNode* nd;
        tri() {
            r = c = -1;
            nd = nullptr;
        }
        tri(ll row, ll col, TreeNode* tn) {
            r = row;
            c = col;
            nd = tn;
        }
    };
public:

    class cmp {
    public:
        bool operator()(const pi& a, const pi& b)const {
            return (a.first == b.first ? a.second->val < b.second->val : a.first < b.first);
        }
    };

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        queue<tri>q;
        q.push({ 0, 0, root });
        map < ll, multiset<pi, cmp>>ump;
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (it.nd == nullptr) {
                continue;
            }
            ump[it.c].insert({ it.r, it.nd });
            q.push({ it.r + 1, it.c - 1, it.nd->left });
            q.push({ it.r + 1, it.c + 1, it.nd->right });
        }
        vi(vi(int))res(ump.size());
        ll in = -1;
        for (auto it : ump) {
            ++in;
            for (auto it2 : it.second) {
                res[in].pb(it2.second->val);
            }
        }
        return res;
    }
};