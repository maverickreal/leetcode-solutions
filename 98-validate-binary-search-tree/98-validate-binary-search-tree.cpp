class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vi(ll)func(TreeNode* nd) {
        if (!nd) {
            return vi(ll)({ 1, LLONG_MIN, LLONG_MAX });
        }
        vi(ll) left = func(nd->left), right = func(nd->right);
        if (!left[0] || !right[0]) {
            return vi(ll)({ 0, LLONG_MIN, LLONG_MAX });
        }
        if (left[1] >= nd->val || right[2] <= nd->val) {
            return vi(ll)({ 0, LLONG_MIN, LLONG_MAX });
        }
        return vi(ll)({ 1, max(ll(nd->val),right[1]), min(ll(nd->val),left[2]) });
    }
    bool isValidBST(TreeNode* root) {
        return func(root)[0];
    }
};