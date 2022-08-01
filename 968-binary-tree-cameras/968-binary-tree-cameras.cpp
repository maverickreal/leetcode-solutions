class Solution {
    typedef long long ll;
public:
    ll ans = 0;
    ll func(TreeNode* nd) {
        if (!nd) {
            return 1;
        }
        ll l = func(nd->left), r = func(nd->right);
        if (l == -1 || r == -1) {
            ++ans;
            return 0;
        }
        if (l == 0 || r == 0) {
            return 1;
        }
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if (func(root) == -1) {
            ++ans;
        }
        return ans;
    }
};