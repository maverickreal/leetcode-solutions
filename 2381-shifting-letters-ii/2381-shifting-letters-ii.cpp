class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    string shiftingLetters(string s, vector<vector<int>>& v) {
        ll m = s.length(), n = v.size();
        vi(ll)pre(m, 0);
        for (auto it : v) {
            pre[it[0]] += it[2] == 0 ? -1 : 1;
            if (it[1] < m - 1) {
                pre[it[1] + 1] += it[2] == 0 ? 1 : -1;
            }
        }
        for (ll i = 0;i < m;++i) {
            if (i > 0) {
                pre[i] += pre[i - 1];
            }
            if (pre[i] < 0) {
                s[i] = char('a'+(26 + (s[i] - 'a') - (abs(pre[i]) % 26)) % 26);
            }
            else {
                //cout<<i<<' '<<s[i]<<' '<<pre[i]<<' '<<(26 + (s[i] - 'a') - (abs(pre[i]) % 26)) % 26<<nl;
                s[i] = char('a'+((s[i] - 'a') + pre[i]) % 26);
            }
        }
        // for(ll it:pre){
        //     cout<<it<<' ';
        // }
        // cout<<nl;
        return s;
    }
};