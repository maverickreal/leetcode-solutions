class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll n, res;
    unordered_set<ll>ust;
    void bfs(const vi(int)& e, ll nd) {
        unordered_map<ll, ll> ump;
        ll time = -1;
        while (nd > -1) {
            ++time;
            if (ump.find(nd) != ump.end()) {
                res = max(res, time - ump[nd]);
                break;
            }
            if(ust.find(nd)!=ust.end()){
                break;
            }
            ump[nd] = time;
            ust.insert(nd);
            nd = e[nd];
        }
    }
    int longestCycle(vector<int>& e) {
        n = e.size();
        res = -1;
        for (ll i = 0;i < n;++i) {
            if (ust.find(i) == ust.end()) {
                bfs(e, i);
            }
        }
        return res;
    }
};