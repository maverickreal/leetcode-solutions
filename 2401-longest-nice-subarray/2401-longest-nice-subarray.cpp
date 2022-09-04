class Solution {
    typedef long long ll;
public:
    vector<vector<ll>>pre;

    void findPrefixCount(const vector<int>& v) {
        for (int i = 0; i < 32; i++) {
            pre[i][0] = ((v[0] >> i) & 1);
            for (int j = 1; j < v.size(); j++) {
                pre[i][j] = ((v[j] >> i) & 1) + pre[i][j - 1];
            }
        }
    }
    int rangeOr(ll l, ll r) {
        ll ans = 0;
        for (int i = 0; i < 32; i++) {
            ll x = pre[i][r];
            if (l > 0) {
                x -= pre[i][l - 1];
            }
            if (x != 0) {
                ans |= (1 << i);
            }
        }
        return ans;
    }
    int longestNiceSubarray(vector<int>& v) {
        ll sz = v.size(), res = 1, left = 0;
        pre.assign(32, vector<ll>(sz));
        findPrefixCount(v);
        for (ll i = 1;i < sz;++i) {
            while (left < i && (rangeOr(left, i - 1) & v[i])) {
                ++left;
            }
            res = max(res, i - left + 1);
        }
        return res;
    }
};