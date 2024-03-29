class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll ans = 0;
    pi func(TreeNode* nd) {
        if(!nd){
            return {-1,-1};
        }
        pi p = { func(nd->left).second + 1, func(nd->right).first + 1 };
        ans = max({ans, p.first, p.second});
        return p;
    }
    int longestZigZag(TreeNode* root) {
        func(root);
        return ans;
    }
};