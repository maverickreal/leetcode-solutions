class Solution {
public:
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    int pseudoPalindromicPaths(TreeNode* root, ll n = 0) {
        if (!root) return 0;
        n ^= (1 << (root->val - 1));
        if (!(root->left || root->right)) {
            ll cnt = 0, m = n;
            while (m) {
                cnt += m & 1;
                m >>= 1;
            }
            return (cnt < 2);
        }
        return (pseudoPalindromicPaths(root->left, n) + pseudoPalindromicPaths(root->right, n));
    }
};