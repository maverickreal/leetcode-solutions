class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
vi(vi(ll))dp;
ll func(const int&n, ll in, ll bm){
	if(in==n+1){
		return 1;
	}
	ll&ans=dp[in][bm];
	if(ans==-1){
        ans=0;
		for(ll i=1;i<=n;++i){
			if(((bm>>i)&1)==0 && !(in%i && i%in)){
				ans+=func(n, in+1, bm|(1<<i));
			}
		}
	}
	return ans;
}
    int countArrangement(int n) {
		dp.resize(n+1, vi(ll)(1<<(n+1), -1));
        return func(n, 1, 0);
    }
};