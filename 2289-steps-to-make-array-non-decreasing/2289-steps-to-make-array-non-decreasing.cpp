typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define endl '\n'
#define tn TreeNode
#define ln ListNode
const ll mod = 1e9;

class Solution {
public:
    int totalSteps(vector<int>& v) {
        ll sz = v.size();
        stack<pair<ll, ll>>st;
        ll res = 0;
        for (ll i = sz - 1;i > -1;--i) {
            ll cnt = 0;
            while (!st.empty() && st.top().first < v[i]) {
                cnt = max(cnt + 1, st.top().second);
                st.pop();
            }
            res = max(res, cnt);
            st.push({ v[i], cnt });
        }
        return res;
    }
};