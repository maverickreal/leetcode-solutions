typedef long long ll;
#define endl '\n'
const ll mod = 1e9 + 7;

class Solution {
public:
    long long appealSum(const string& s) {
        ll sz = s.length();
        vector<ll>dp(sz), lasPos(26);
        lasPos[s.front()-'a']++;
        ++dp.front();
        for (ll i = 1;i < sz;++i) {
            dp[i] = dp[i - 1] + i + 1 - lasPos[s[i] - 'a'];
            lasPos[s[i] - 'a'] = i + 1;
        }
        return accumulate(dp.begin(), dp.end(), 0LL);
    }
};