class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    unordered_map<TreeNode*, pi>ump;
    int rob(TreeNode* root, bool take = true) {
        if (!root) {
            return 0;
        }
        if (ump.find(root) == ump.end()) {
            ll ans = rob(root->left) + rob(root->right);
            ump[root].second = ans;
            if (take) {
                ans = max(ans, ll(root->val + rob(root->left, false) + rob(root->right, false)));
            }
            ump[root].first = ans;
        }
        return (take ? ump[root].first : ump[root].second);
    }
};