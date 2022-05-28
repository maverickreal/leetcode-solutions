class Solution {
#define ln ListNode
#define tn TreeNode
#define endl '\n'
    typedef long long ll;
    typedef vector<ll> vi;
    const ll mod = 1e9;
public:
    long long maximumImportance(ll n, vector<vector<int>>& v) {
        vector<pair<ll, ll>>ump(n);
        for (ll i = 0;i < n;++i)
            ump[i] = { 0,i };
        for (auto& it : v) {
            ++ump[it[0]].first;
            ++ump[it[1]].first;
        }
        sort(ump.begin(), ump.end());
        ll id = n;
        vi ans(n);
        for (ll i = n - 1;i > -1;--i)
            ans[ump[i].second] = id--;
        ll res = 0;
        for (auto& it : v)
            res += ans[it[0]] + ans[it[1]];
        return res;
    }
};