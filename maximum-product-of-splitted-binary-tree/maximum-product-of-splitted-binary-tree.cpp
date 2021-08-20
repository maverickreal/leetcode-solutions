class Solution {
public:
#define tn TreeNode
#define ll long long
    ll res = 0, sum = 0;
    ll func(tn* nd) {
        if (!nd)
            return 0;
        ll cur = func(nd->left) + func(nd->right) + nd->val;
        res = max(res, cur * (sum - cur));
        return cur;
    }
    int maxProduct(TreeNode* rt) {
        queue<tn*>q;
        q.push(rt);
        while (!q.empty()) {
            tn* nd = q.front();
            if (nd) {
                q.push(nd->left);
                q.push(nd->right);
                sum += nd->val;
            }
            q.pop();
        }
        func(rt);
        //cout<<sum;
        return res%1000000007;
    }
};