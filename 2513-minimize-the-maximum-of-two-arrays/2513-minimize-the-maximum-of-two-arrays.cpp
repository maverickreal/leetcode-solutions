class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
static const ll mod = 1e9 + 7;
static const char nl = '\n';
const vi(vi(ll))dirs={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
bool func(ll l, ll d1, ll d2, ll c1, ll c2){
    ll gfa=l-(l/d1), gfb=l-(l/d2), gfab=l-((l/d1)+(l/d2)-(l/lcm(d1, d2))); // g.f.x. => Good For list X
    ll reqa=(gfa-gfab)>=c1?0:(c1-gfa+gfab), reqb=(gfb-gfab)>=c2?0:(c2-gfb+gfab);
    return (reqa+reqb<=gfab);
}
int minimizeSet(int d1, int d2, int c1, int c2) {
    ll l=c1+c2, r=mod*mod, ans=-1;
    while(l<=r){
        ll m=l+((r-l)>>1);
        if(func(m, d1, d2, c1, c2)){
            ans=m, r=m-1;
        }
        else{
            l=m+1;
        }
    }
    return ans;
}
};