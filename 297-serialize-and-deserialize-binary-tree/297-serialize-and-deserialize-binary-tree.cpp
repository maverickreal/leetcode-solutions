class Codec {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    string serialize(TreeNode* root) {
        string res;
        queue<TreeNode*>q;
        q.push(root);
        while (!q.empty()) {
            auto it = q.front();
            q.pop();
            res.append(it ? to_string(it->val) : "n");
            res.push_back(',');
            if (it) {
                q.push(it->left);
                q.push(it->right);
            }
        }
        res.pop_back();
        return res;
    }
    TreeNode* deserialize(const string& s) {
        TreeNode* root = new TreeNode(0);
        ll state = 1;
        queue<TreeNode*>q;
        q.push(root);
        ll sz = s.length();
        for (ll i = 0;i < sz;++i) {
            ll j = i;
            while (i < sz && s[i] != ',') {
                ++i;
            }
            string nodeStr = s.substr(j, i - j);
            TreeNode* node = nullptr;
            if (nodeStr != "n") {
                node = new TreeNode(stoll(nodeStr));
            }
            while (!q.empty() && q.front() == nullptr) {
                q.pop();
            }
            if (q.empty()) {
                break;
            }
            TreeNode* it = q.front();
            if (state == 0) {
                it->left = node;
            }
            else {
                it->right = node;
            }
            ++state;
            if (state == 2) {
                state = 0;
                q.pop();
                q.push(it->left);
                q.push(it->right);
            }
        }
        return root->right;
    }
};