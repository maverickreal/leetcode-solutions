class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    int subarrayBitwiseORs(vector<int>& v) {
        unordered_set<ll>ans, pre;
        for (ll it : v) {
            unordered_set<ll>cur;
            for (ll ti : pre) {
                cur.insert(ti | it);
                ans.insert(it | ti);
            }
            cur.insert(it);
            ans.insert(it);
            pre = cur;
        }
        return ans.size();
    }
};