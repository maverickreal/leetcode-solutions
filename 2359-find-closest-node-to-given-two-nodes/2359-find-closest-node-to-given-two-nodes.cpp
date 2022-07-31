class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll n;
    void bfs(const vi(int)& e, ll nd, unordered_map<ll, ll>& ump) {
        unordered_set<ll>ust;
        ll time = -1;
        while (nd > -1 && ust.find(nd) == ust.end()) {
            ++time;
            ump[nd] = time;
            ust.insert(nd);
            nd = e[nd];
        }
    }
    int closestMeetingNode(vector<int>& e, int a, int b) {
        unordered_map<ll, ll>umpa, umpb;
        n = e.size();
        bfs(e, a, umpa);
        bfs(e, b, umpb);
        ll res = -1, resNd = -1;
        for (ll i = 0;i < n;++i) {
            if (umpa.find(i) != umpa.end() && umpb.find(i) != umpb.end()) {
                ll mx = max(umpa[i], umpb[i]);
                if (resNd == -1 || mx < res) {
                    resNd = i;
                    res = mx;
                }
            }
        }
        return resNd;
    }
};