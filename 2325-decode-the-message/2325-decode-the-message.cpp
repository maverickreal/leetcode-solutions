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
string decodeMessage(string& key, string& s) {
    ll szk = key.length(), szs = s.length();
    vi(char)sub(26, '.');
    char chr = 'a';
    for (const char& ch : key)
        if (ch != ' ' && sub[ch-'a']=='.')
            sub[ch - 'a'] = chr++;
    for (char& ch : s)
        if (ch != ' ')
            ch = sub[ch - 'a'];
    return s;
}
};