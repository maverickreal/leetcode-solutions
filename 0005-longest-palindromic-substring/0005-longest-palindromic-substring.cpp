class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
#define ln ListNode

string longestPalindrome(const string&str) {
    ll n=str.size(), m=2*n+1;
    string sDash(m, '#');
    for(ll i=0;i<n;++i){
        sDash[2*i+1]=str[i];
    }
    vi(ll)cp(m);
    ll lpc=0, lps=0, rpc=0, rpr=0;
    for(ll i=0;i<m;++i){
        if(i<rpr){
            cp[i]=min(rpr-i, cp[2*rpc-i]);
        }
        ll l=i-cp[i]-1, r=i+cp[i]+1;
        while(l>-1 && r<m && sDash[l]==sDash[r]){
            --l, ++r, ++cp[i];
        }
        if(cp[i]>lps){
            lps=cp[i], lpc=i;
        }
        if(i+cp[i]>rpr){
            rpr=cp[i]+i, rpc=i;
        }
    }
    string ans;
    for(ll i=lpc-lps;i<=lpc+lps;++i){
        if(sDash[i]!='#'){
            ans.pb(sDash[i]);
        }
    }
    return ans;
}
};