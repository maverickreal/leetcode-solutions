typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define endl '\n'
#define tn TreeNode
#define ln ListNode
const ll mod = 1e9;

class Solution {
public:
    vector<int>res;
    void bfs(tn* nd, ll d) {
        if (d < 0)
            return;
        queue<pair<tn*, ll>>q;
        q.push({ nd, 0 });
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            if (!it.first || it.second > d)continue;
            if (it.second == d)
                res.push_back(it.first->val);
            q.push({ it.first->left, it.second + 1 });
            q.push({ it.first->right, it.second + 1 });
        }
    }
    ll func(tn* rt, tn* tar, ll k) {
        if (!rt)
            return -1;
        if (rt->val == tar->val) {
            bfs(tar, k);
            return 0;
        }
        ll l = func(rt->left, tar, k);
        if (l > -1) {
            if (l == k - 1)
                res.push_back(rt->val);
            bfs(rt->right, k - l - 2);
            return l + 1;
        }
        ll r = func(rt->right, tar, k);
        if (r > -1) {
            if (r == k - 1)
                res.push_back(rt->val);
            bfs(rt->left, k - r - 2);
            return r + 1;
        }
        return -1;
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        func(root, target, k);
        return res;
    }
};