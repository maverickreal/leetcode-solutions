class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(ll)ump;
    TreeNode* xPar = nullptr, * xLeft = nullptr, * xRight = nullptr;
    ll count(TreeNode* nd, TreeNode* par, const ll& x) {
        if (!nd) {
            return  0;
        }
        if (nd->val == x) {
            xPar = par;
            xLeft = nd->left;
            xRight = nd->right;
        }
        ump[nd->val] = 1 + count(nd->left, nd, x) + count(nd->right, nd, x);
        return ump[nd->val];
    }
    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        ump.resize(n + 1, 0);
        count(root, nullptr, x);
        if (xPar && n > (2 * ump[x])) {
            return true;
        }
        if (xLeft && n < (2 * ump[xLeft->val])) {
            return true;
        }
        return (xRight && n < (2 * ump[xRight->val]));
    }
};