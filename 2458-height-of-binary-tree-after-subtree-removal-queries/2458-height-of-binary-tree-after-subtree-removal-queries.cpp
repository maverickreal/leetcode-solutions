class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(ll)d, h;
    vi(pi)mx;
    ll dfs(TreeNode*nd, ll level){
        if(!nd){
            return 0;
        }
        h[nd->val]=level;
        ll rec=max(dfs(nd->left, level+1), dfs(nd->right, level+1))+1;
        d[nd->val]=rec;
        if(rec>mx[level].first){
            mx[level].second=mx[level].first, mx[level].first=rec;
        }
        else{
            mx[level].second=max(mx[level].second, rec);
        }
        return rec;
    }
    vector<int> treeQueries(TreeNode* root, vector<int>&q) {
        h.resize(1e5+1), d.resize(1e5+1), mx.resize(1e5+1);
        dfs(root, 0);
        vi(int)ans(q.size());
        for(ll i=0;i<q.size();++i){
            ll level=h[q[i]], res=mx[level].first==d[q[i]]?mx[level].second:mx[level].first;
            ans[i]=level+res-1;
        }
        return ans;
    }
};