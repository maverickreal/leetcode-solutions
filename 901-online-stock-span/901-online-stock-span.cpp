class StockSpanner {
public:
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    list<pi>st;
    ll sz = 0;
    StockSpanner() {

    }

    int next(int n) {
        ll res = ++sz;
        while (!st.empty() && st.back().first <= n) {
            st.pop_back();
        }
        if (!st.empty()) {
            res -= st.back().second;
        }
        st.pb({ n, sz });
        return res;
    }
};