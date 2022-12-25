class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int closetTarget(vector<string>&v, string&tar, int start) {
        ll n=v.size(), ans=LLONG_MAX;
        for(ll in=0;in<n;++in){
            if(v[in]!=tar){
                continue;
            }
            ll res=abs(in-start);
            if(start<=in){
                res=min(res, start+n-in);
            }
            else{
                res=min(res, n-start+in);
            }
            ans=min(ans, res);
        }
        return (ans==LLONG_MAX?-1:ans);
    }
};