class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    string largestPalindromic(string& s) {
        string res = "";
        ll sz = s.length();
        vi(ll)ump(10, 0);
        for (char ch : s) {
            ++ump[ch - '0'];
        }
        ll last = -1;
        for (ll i = 9;i > -1;--i) {
            if (ump[i] > 1) {
                res.append(string(ump[i] / 2, '0' + i));
                ump[i] &= 1;
            }
            if (last == -1 && ump[i] == 1) {
                last = i;
            }
        }
        string tmp = res;
        reverse(tmp.begin(), tmp.end());
        if(last>-1){
            res.pb('0' + last);
        }
        res.append(tmp);
        ll zeroCnt = 0;
        while (!res.empty() && res.back() == '0') {
            res.pop_back();
            ++zeroCnt;
        }
        if (!res.empty()) {
            res = res.substr(zeroCnt);
        }
        if (res.empty()) {
            res = "0";
        }
        return res;
    }
};