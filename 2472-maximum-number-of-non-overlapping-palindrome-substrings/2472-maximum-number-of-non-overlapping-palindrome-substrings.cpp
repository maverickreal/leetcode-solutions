class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
ll n, k;
string s;
vi(vi(ll))dp, memo;
bool palin(ll l, ll r){
    if(l>=r){
        return 1;
    }
    ll&ans=memo[l][r];
    if(ans==-1){
        ans=palin(l+1, r-1) && s[l]==s[r];
    }
    return ans;
}
ll func(ll in, ll pre){
    if(in==n){
        return (in-pre>=k && palin(pre, in-1));
    }
    ll&ans=dp[pre][in];
    if(ans==-1){
        ll take=func(in+1, pre), dont=(in-pre+1>=k && palin(pre, in))+func(in+1, in+1);
        ans=max(take, dont);
    }
    return ans;
}
    int maxPalindromes(const string&str, int K) {
        s=move(str), n=s.size(), k=K, dp.assign(n, vi(ll)(n, -1)), memo.assign(n, vi(ll)(n, -1));
        return func(0, 0);
    }
};