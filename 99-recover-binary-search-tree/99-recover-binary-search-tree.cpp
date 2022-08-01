class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    void recoverTree(TreeNode* root) {
        TreeNode* a = nullptr, * b = nullptr, * c = nullptr, * nd = root;
        bool cExist = false;
        while (nd) {
            if (!nd->left) {
                if (!cExist) {
                    if (b) {
                        if (nd->val < c->val) {
                            c = nd;
                            cExist = true;
                        }
                        c = nd;
                    }
                    else {
                        if (a && nd->val < a->val) {
                            b = nd;
                            c = nd;
                        }
                        else {
                            a = nd;
                        }
                    }
                }
                nd = nd->right;
            }
            else {
                TreeNode* check = nd->left;
                while (check->right && check->right != nd) {
                    check = check->right;
                }
                if (!check->right) {
                    check->right = nd;
                    nd = nd->left;
                }
                else {
                    check->right = nullptr;
                    if (!cExist) {
                        if (b) {
                            if (nd->val < c->val) {
                                c = nd;
                                cExist = true;
                            }
                            c = nd;
                        }
                        else {
                            if (a && nd->val < a->val) {
                                b = nd;
                                c = nd;
                            }
                            else {
                                a = nd;
                            }
                        }
                    }
                    nd = nd->right;
                }
            }
        }
        // if (a) {
        //     cout << a->val << ' ';
        // }
        // if (b) {
        //     cout << b->val << ' ';
        // }
        // if (c) {
        //     cout << cExist << ' ' << c->val << ' ';
        // }
        if (cExist) {
            c->val += a->val;
            a->val = c->val - a->val;
            c->val -= a->val;
        }
        else {
            a->val += b->val;
            b->val = a->val - b->val;
            a->val -= b->val;
        }
    }
};