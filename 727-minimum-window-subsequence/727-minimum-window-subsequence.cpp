class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    ll m, n, l, r;
    vi(vi(pi))dp;
    pi func(const string& a, const string& b, ll i, ll j) {
        if (j == n) {
            return { i - 1, 1 };
        }
        if (i == m) {
            return { -1,-1 };
        }
        if (dp[i][j] == pi({-2, -2})) {
            pi dont = func(a, b, i + 1, j), take = { -1,-1 };
            if (a[i] == b[j]) {
                take = func(a, b, i + 1, j + 1);
            }
            if (take.first == -1 && dont.first == -1) {
                dp[i][j] = { -1,-1 };
            }
            else if (take.first == -1) {
                dp[i][j] = dont;
            }
            else {
                take.second += take.first - i, take.first = i;
                if (dont.first == -1) {
                    dp[i][j] = take;
                }
                else {
                    ll takein = take.first + take.second - 1, dontin = dont.first + dont.second - 1;
                    dp[i][j] = (takein <= dontin ? take : dont);
                }
            }
        }
        //cout<<i<<' '<<j<<' '<<dp[i][j].first<<' '<<dp[i][j].second<<nl;
        if(j==0 && (l==-1 || dp[i][j].second<r || (dp[i][j].second==r && dp[i][j].first+dp[i][j].second<l+r))){
            l=dp[i][j].first, r=dp[i][j].second;
        }
        return dp[i][j];
    }
    string minWindow(string& a, string& b) {
        m = a.size(), n = b.size(), l=r=-1;
        dp.assign(m, vi(pi)(n, { -2,-2 }));
        func(a, b, 0, 0);
        if (l == -1) {
            return "";
        }
        return a.substr(l, r);
    }
};