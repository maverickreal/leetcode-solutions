class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int longestAwesome(const string&s) {
        ll n=s.size(), bm=0, ans=1;
        vi(ll)ump(1024, n);
        ump[0]=-1;
        for(ll i=0;i<n;++i){
            bm^=1<<(s[i]-'0');
            ans=max(ans, i-ump[bm]);
            for(ll j=0;j<10;++j){
                ans=max(ans, i-ump[bm^(1<<j)]);
            }
            ump[bm]=min(ump[bm], i);
        }
        return ans;
    }
};