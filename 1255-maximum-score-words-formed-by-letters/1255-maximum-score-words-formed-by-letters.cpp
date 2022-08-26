class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll n;
    vi(vi(ll))wf;
    vi(ll)ws;
    ll func(const vi(string)& v, ll in, vi(ll)& c, const vi(int)& s) {
        if (in == n) {
            return 0;
        }
        ll ans = func(v, in + 1, c, s);
        bool take = true;
        for (ll i = 0;i < 26;++i) {
            if (c[i] < wf[in][i]) {
                take = false;
                break;
            }
        }
        if (take) {
            for (ll i = 0;i < 26;++i) {
                c[i] -= wf[in][i];
            }
            ans = max(ans, ws[in] + func(v, in + 1, c, s));
            for (ll i = 0;i < 26;++i) {
                c[i] += wf[in][i];
            }
        }
        return ans;
    }
    int maxScoreWords(vector<string>& w, vector<char>& c, vector<int>& s) {
        n = w.size();
        wf.resize(n, vi(ll)(26, 0));
        ws.resize(n, 0);
        for (ll i = 0;i < n;++i) {
            ll sc = 0;
            for (char ch : w[i]) {
                sc += s[ch - 'a'];
                ++wf[i][ch - 'a'];
            }
            ws[i] = sc;
        }
        vi(ll)rem(26, 0);
        for (char ch : c) {
            ++rem[ch - 'a'];
        }
        return func(w, 0, rem, s);
    }
};