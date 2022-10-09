class Solution {
typedef long long ll;
typedef pair<char, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    string robotWithString(const string&s) {
        ll n=s.size();
        list<char>l;
        string ans, mn=s;
        for(ll i=n-2;i>-1;--i){
            mn[i]=min(s[i], mn[i+1]);
        }
        for(ll i=0;i<n;++i){
            l.pb(s[i]);
            while(!l.empty() && l.back()<=mn[i+1]){
                ans.pb(l.back());
                l.pop_back();
            }
        }
        while(!l.empty()){
            ans.pb(l.back());
            l.pop_back();
        }
        return ans;
    }
};