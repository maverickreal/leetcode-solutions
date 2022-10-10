class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int longestValidParentheses(const string&s) {
        ll n=s.size(), ans=0;
        list<ll>l={-1};
        for(ll i=0;i<n;++i){
            if(s[i]=='('){
                l.pb(i);
            }
            else{
                l.pop_back();
                if(l.empty()){
                    l.pb(i);
                }
                else{
                    ans=max(ans, i-l.back());
                }
            }
        }
        return ans;
    }
};