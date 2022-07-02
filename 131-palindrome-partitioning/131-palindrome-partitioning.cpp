class Solution {
public:
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
    ll sz;
vi(vi(string))res;
bool palin(const vi(string)& v) {
    for (const string& s : v) {
        ll i = 0, j = s.length() - 1;
        while (i < j) {
            if (s[i] != s[j])return false;
            i++;
            j--;
        }
    }
    return true;
}
void func(const string& s, ll i, vi(string)& v) {
    ++i;
    if (i == sz) {
        if (palin(v))
            res.pb(v);
        return;
    }
    v.pb(s.substr(i, 1));
    func(s, i, v);
    v.pop_back();
    v.back().pb(s[i]);
    func(s, i, v);
    v.back().pop_back();
}
vector<vector<string>> partition(string& s) {
    sz = s.length();
    vi(string)v={s.substr(0,1)};
    func(s, 0, v);
    return res;
}
};