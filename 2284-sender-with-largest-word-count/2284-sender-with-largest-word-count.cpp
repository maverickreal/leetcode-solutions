class Solution {
#define ln ListNode
#define tn TreeNode
#define endl '\n'
    typedef long long ll;
    typedef vector<ll> vi;
    const ll mod = 1e9;
public:
    string largestWordCount(vector<string>& m, vector<string>& s) {
        ll sz = m.size();
        unordered_map<string, ll>ump;
        for (ll i = 0;i < sz;++i) {
            string& snd = s[i];
            ll cnt = 1;
            for (char& ch : m[i])
                if (ch == ' ')
                    cnt++;
            ump[snd] += cnt;
        }
        string snd="";
        for (auto& it : ump) {
            if (snd.empty() || it.second > ump[snd] || (it.second == ump[snd] && it.first > snd))
                snd = it.first;
        }
        return snd;
    }
};