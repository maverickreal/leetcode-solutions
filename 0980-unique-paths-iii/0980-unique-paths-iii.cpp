class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
ll m, n, tar;
vi(vi(vi(ll)))dp;
vi(vi(ll))dirs={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
ll func(const vi(vi(int))&v, ll i, ll j, ll bm){
	ll pos=(n*i)+j;
    bm|=1<<pos;
    if(v[i][j]==2){
		return __builtin_popcount(bm)==tar;
	}
	ll&ans=dp[i][j][bm];
	if(ans==-1){
		ans=0;
		for(const vi(ll)&dir:dirs){
            ll x=i+dir[0], y=j+dir[1];
            if(x<0 || y<0 || x>=m || y>=n || v[x][y]==-1){
                continue;
            }
            pos=(n*x)+y;
            if(!((bm>>pos)&1)){
			    ans+=func(v, x, y, bm);
            }
	    }
	}
	return ans;
}
int uniquePathsIII(vector<vector<int>>&v) {
	m=v.size(), n=v[0].size(), tar=m*n;
	dp.resize(m, vi(vi(ll))(n, vi(ll)(1<<(m*n), -1)));
	ll start=0, end=0;
	for(ll i=0;i<m;++i){
		for(ll j=0;j<n;++j){
			if(v[i][j]==1){
				start=i, end=j;
			}
			else if(v[i][j]==-1){
				--tar;
			}
		}
	}
	return func(v, start, end, 0);
}
};