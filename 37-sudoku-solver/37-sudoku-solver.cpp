class Solution {
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define endl '\n'
const ll mod = 1e9;

bool feasible(const vi(vi(char))& v, ll i, ll j, const char& ch) {
    for (ll k = 0;k < 9;++k) {
        if (v[k][j] == ch || v[i][k] == ch)
            return false;
    }
    vi(bool)visited(10, false);
    ll x = i / 3, y = j / 3;
    for (ll k = 0;k < 3;++k) {
        for (ll l = 0;l < 3;++l) {
            const char& tmp = v[x * 3 + k][y * 3 + l];
            if (tmp == '.')
                continue;
            if (visited[tmp - '0'])
                return false;
            visited[tmp - '0'] = true;
        }
    }
    return true;
}
    
public:

bool solveSudoku(vi(vi(char))& v, ll i = 0, ll j = 0) {
    if (j == 9) {
        ++i;
        j = 0;
    }
    if (i == 9)
        return true;
    if (v[i][j] != '.')
        return solveSudoku(v, i, j + 1);
    for (char ch = '1';ch <= '9';++ch) {
        if (feasible(v, i, j, ch)) {
            v[i][j] = ch;
            if(solveSudoku(v, i, j + 1))
                return true;
            v[i][j] = '.';
        }
    }
    return false;
}
};