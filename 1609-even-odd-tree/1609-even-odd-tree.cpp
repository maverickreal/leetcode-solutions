class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    bool isEvenOddTree(TreeNode* root) {
        list<TreeNode*>q={root};
        bool odd = false;
        while (!q.empty()) {
            ll sz = q.size(), pre = odd ? LLONG_MAX : LLONG_MIN;
            while (sz--) {
                auto it = q.front();
                q.pop_front();
                if (it == nullptr) {
                    continue;
                }
                if (odd && (it->val & 1 || it->val >= pre)) {
                    return false;
                }
                if (!odd && (!(it->val & 1) || it->val <= pre)) {
                    return false;
                }
                pre = it->val;
                q.push_back(it->left);
                q.push_back(it->right);
            }
            odd = !odd;
        }
        return true;
    }
};