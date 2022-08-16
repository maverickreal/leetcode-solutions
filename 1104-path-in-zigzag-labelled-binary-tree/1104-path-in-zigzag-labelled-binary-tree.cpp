class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    vector<int> pathInZigZagTree(int label) {
        ll lab = label, row = 0;
        while (lab) {
            ++row;
            lab >>= 1;
        }
        bool dirLeft = row & 1;
        vi(int)res;
        while (row > 0) {
            res.pb(label);
            ll start = 1 << (row - 1), end = (1 << row) - 1;
            if (dirLeft) {
                ll dif = label - start;
                dif /= 2;
                ll parEnd = (1 << (row - 1)) - 1;
                label = parEnd - dif;
            }
            else {
                ll dif = end - label;
                dif /= 2;
                ll parStart = 1 << (row - 2);
                label = parStart + dif;
            }
            --row;
            dirLeft = !dirLeft;
        }
        reverse(res.begin(), res.end());
        return res;
    }
};