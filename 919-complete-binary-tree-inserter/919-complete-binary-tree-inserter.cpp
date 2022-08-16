class CBTInserter {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    TreeNode* root;
    vi(TreeNode*)par, nodes;
    ll depth;
    CBTInserter(TreeNode* rt) {
        root = rt;
        ll d = 0;
        while (rt) {
            ++d;
            rt = rt->left;
        }
        depth = d;
        par = { root };
        ll parDepth = 1;
        if (root->left) {
            nodes.pb(root->left);
        }
        if (root->right) {
            nodes.pb(root->right);
        }
        while (d > 2) {
            ++parDepth;
            par = nodes;
            nodes.clear();
            for (auto p : par) {
                nodes.pb(p->left);
                nodes.pb(p->right);
            }
            while (!nodes.empty() && nodes.back() == nullptr) {
                nodes.pop_back();
            }
            --d;
        }
        ll parCnt = 1 << (parDepth - 1);
        if (par.size() == parCnt && nodes.empty()) {
            ++depth;
        }
    }

    int insert(int val) {
        ll ans = -1;
        if (nodes.size() < (1 << (depth - 1))) {
            ll parPos = nodes.size() / 2;
            if (nodes.size() & 1) {
                par[parPos]->right = new TreeNode(val);
                nodes.pb(par[parPos]->right);
            }
            else {
                par[parPos]->left = new TreeNode(val);
                nodes.pb(par[parPos]->left);
            }
            ans = par[parPos]->val;
        }
        else {
            ++depth;
            par = nodes;
            nodes.clear();
            par.front()->left = new TreeNode(val);
            nodes.pb(par.front()->left);
            ans = par.front()->val;
        }
        return ans;
    }

    TreeNode* get_root() {
        return root;
    }
};