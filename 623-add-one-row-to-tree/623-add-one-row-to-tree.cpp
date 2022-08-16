class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    void dfs(TreeNode* rt, ll d, ll val, ll depth) {
        if (!rt || d >= depth) {
            return;
        }
        ++d;
        if (d == depth - 1) {
            TreeNode* l = rt->left, * r = rt->right;
            rt->left = new TreeNode(val);
            rt->right = new TreeNode(val);
            rt->left->left = l;
            rt->right->right = r;
        }
        dfs(rt->left, d, val, depth);
        dfs(rt->right, d, val, depth);
    }
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (depth == 1) {
            TreeNode* nd = new TreeNode(val);
            nd->left = root;
            return nd;
        }
        dfs(root, 0, val, depth);
        return root;
    }
};