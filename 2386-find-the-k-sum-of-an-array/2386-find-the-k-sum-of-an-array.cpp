class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    long long kSum(vector<int>& v, int k) {
        ll sz = v.size(), ans = 0;
        for (auto& it : v) {
            if (it > -1) {
                ans += it;
            }
            it = abs(it);
        }
        sort(v.begin(), v.end());
        priority_queue<pi>pq;
        pq.push({ ans - v[0],0 });
        while (--k) {
            pi p = pq.top();
            pq.pop();
            ans = p.first;
            if (p.second < sz - 1) {
                pq.push({ p.first - v[p.second + 1],p.second + 1 });
                pq.push({ p.first - v[p.second + 1] + v[p.second],p.second + 1 });
            }
        }
        return ans;
    }
};