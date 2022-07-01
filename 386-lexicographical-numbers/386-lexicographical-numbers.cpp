class Solution {
public:
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define endl '\n'
const ll mod = 1e9;

vi(int)res;

bool func(ll cur, const ll& n) {
    if (res.size() == n)
        return true;
    if(cur>n)
        return false;
    res.push_back(cur);
    for (ll i = 0;i <= 9;++i)
        if (func(cur * 10 + i, n))
            return true;
    return false;
}

vector<int> lexicalOrder(ll n) {
    for(ll i=1;i<=n;++i)
    func(i, n);
    return res;
}
};