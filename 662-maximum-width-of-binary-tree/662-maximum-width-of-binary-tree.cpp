class Solution {
    typedef unsigned long long ll;
    typedef pair<TreeNode*, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int widthOfBinaryTree(TreeNode* root) {
        list<pi>q;
        q.push_back(pi(root, 0));
        ll ans = 1;
        while (!q.empty()) {
            ans = max(ans, q.back().second - q.front().second + 1);
            ll sz = q.size();
            for (ll i = 0;i < sz;++i) {
                pi p = q.front();
                q.pop_front();
                if (p.first->left) {
                    q.push_back({ p.first->left, p.second * 2 + 1 });
                }
                if (p.first->right) {
                    q.push_back({ p.first->right, p.second * 2 + 2 });
                }
            }
        }
        return ans;
    }
};