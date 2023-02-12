class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9+7;
const char nl = '\n';

bool cmp(const pi&a, const pi&b){
    const auto&[xs, xe]=a;
    const auto&[ys, ye]=b;
    ll szx=xe-xs+1, szy=ye-ys+1;
    if(szx==szy){
        return (xs<ys);
    }
    return (szx<szy);
}

vector<vector<int>> substringXorQueries(const string&s, vector<vector<int>>&q) {
    ll n=s.size();
    unordered_map<ll, pi>ump;
    for(ll i=0;i<n;++i){
        ll num=0;
        for(ll j=i;j>-1 && i-j+1<33;--j){
            ll cur=s[j]-'0';
            num=(cur<<(i-j))+num;
            if(ump.find(num)==ump.end() || cmp({j, i}, ump[num])){
                ump[num]={j,i};
            }
        }
    }
    ll m=q.size();
    vi(vi(int))ans(m, {-1, -1});
    // for(auto&[k, v]:ump){
    //     sort(begin(v), end(v), cmp);
    // }
    // for(const auto&[k, v]:ump){
    //     cout<<k<<' '<<v.first<<' '<<v.second<<nl;
    // }
    for(ll i=0;i<m;++i){
        ll xo=q[i][0]^q[i][1];
        if(ump.find(xo)!=ump.end()){
            ans[i]={(int)ump[xo].first, (int)ump[xo].second};
        }
    }
    return ans;
}
};