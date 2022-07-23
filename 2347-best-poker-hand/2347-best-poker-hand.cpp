class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool best = true;
        for (ll i = 1;i < 5;++i) {
            if (suits[i] != suits[i - 1]) {
                best = false;
                break;
            }
        }
        if (best) {
            return "Flush";
        }
        unordered_map<int, int>ump;
        for (ll it : ranks) {
            ++ump[it];
        }
        bool sec = false;
        for (auto it : ump) {
            if (it.second > 2) {
                return "Three of a Kind";
            }
            if (it.second > 1) {
                sec = true;
            }
        }
        return (sec ? "Pair" : "High Card");
    }
};