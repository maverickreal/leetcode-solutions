class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll n;
    vi(ll)sum;
    ll func(const vi(int)& cc, const vi(int)& rc, ll k) {
        if (k == 0) {
            return 0;
        }
        priority_queue<pi>pq;
        for (ll i = 0;i < k;++i) {
            pq.push({ cc[i],i });
        }
        ll ans = (sum[k - 1] * k) + pq.top().first;
        //cout << k << ' ' << sum[k] << ' ' << pq.top().first << nl;
        for (ll i = 1;i + k - 1 < n;++i) {
            pq.push({ cc[i + k - 1], i + k - 1 });
            while (pq.top().second < i) {
                pq.pop();
            }
            ans = min(ans, (sum[i + k - 1] - sum[i - 1]) * k + pq.top().first);
        }
        //cout<<"ret : "<<ans<<nl;
        return ans;
    }
    int maximumRobots(vector<int>& cc, vector<int>& rc, ll b) {
        n = cc.size();
        sum.assign(n, 0);
        sum[0] = rc[0];
        for (ll i = 1;i < n;++i) {
            sum[i] = sum[i - 1] + rc[i];
        }
        ll ans = 0, l = 0, r = n;
        while (l <= r) {
            ll m = l + ((r - l) >> 1), req = func(cc, rc, m);
            if (req <= b) {
                ans = m;
                l = m + 1;
            }
            else {
                r = m - 1;
            }
        }
        return ans;
    }
};