class Solution {
public:
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define endl '\n'
const ll mod = 1e9;

ll szs, m, n;

bool hor(const vi(vi(char))& v, ll i, ll j, const string& s) {
    if (j && v[i][j - 1] != '#')
        return false;
    if (n - j < szs)
        return false;
    if (j + szs < n && v[i][j + szs] != '#')
        return false;
    bool sp = false;
    for (ll k = j;k < j + szs;k++) {
        if (v[i][k] == '#')
            return false;
        if (v[i][k] == ' ')
            sp = true;
        else if (v[i][k] != s[k - j])
            return false;
    }
    if (!sp && ((j && v[i][j - 1] != '#') || (j + szs < n && v[i][j + szs] != '#')))
        return false;
    //cout<<i<<' '<<j<<' '<<"hor "<<s<<endl;
    return true;
}

bool ver(const vi(vi(char))& v, ll i, ll j, const string& s) {
    if (i && v[i - 1][j] != '#')
        return false;
    if (m - i < szs)
        return false;
    if (i + szs < m && v[i + szs][j] != '#')
        return false;
    bool sp = false;
    for (ll k = i;k < i + szs;k++) {
        if (v[k][j] == '#')
            return false;
        if (v[k][j] == ' ')
            sp = true;
        else if (v[k][j] != s[k - i])
            return false;
    }
    if (!sp && ((i && v[i - 1][j] != '#') || (i + szs < m && v[i + szs][j] != '#')))
        return false;
    //cout<<i<<' '<<j<<' '<<"ver "<<s<<endl;
    return true;
}

bool placeWordInCrossword(vector<vector<char>>& v, string& s) {
    szs = s.length();
    string rs = s;
    m = v.size(), n = v[0].size();
    reverse(rs.begin(), rs.end());
    for (ll i = 0;i < m;++i) {
        for (ll j = 0;j < n;++j) {
            if (hor(v, i, j, s) || ver(v, i, j, s) || hor(v, i, j, rs) || ver(v, i, j, rs)) return true;
        }
    }
    return false;
}
};