class Solution {
public:
    typedef int ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    int kthLargestValue(vector<vector<int>>& v, int k) {
        ll m = v.size(), n = v[0].size();
        priority_queue<ll,vi(ll),greater<ll>>pq;
        for (ll i = 0;i < m;++i) {
            for (ll j = 0;j < n;++j) {
                ll xo = v[i][j];
                if (i)
                    xo ^= v[i - 1][j];
                if (j)
                    xo ^= v[i][j - 1];
                if (i && j)
                    xo ^= v[i - 1][j - 1];
                pq.push(xo);
                if (pq.size() > k)
                    pq.pop();
                v[i][j] = xo;
            }
        }
        // for(vi(ll)it:v){
        //     for(ll ti:it)
        //         cout<<ti<<' ';
        //     cout<<nl;
        // }
        return pq.top();
    }
};