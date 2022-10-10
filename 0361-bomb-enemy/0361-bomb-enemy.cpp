class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll m,n;
    void compUpLeft(const vi(vi(char))&v, vi(vi(vi(ll)))&pre, ll i, ll j){
        if(i>0){
            pre[i][j][0]=pre[i-1][j][0];
        }
        if(j>0){
            pre[i][j][1]=pre[i][j-1][1];
        }
        if(v[i][j]=='E'){
            ++pre[i][j][0], ++pre[i][j][1]; 
        }
    }
    void compDownRight(const vi(vi(char))&v, vi(vi(vi(ll)))&pre, ll i, ll j){
        if(i<m-1){
            pre[i][j][2]=pre[i+1][j][2];
        }
        if(j<n-1){
            pre[i][j][3]=pre[i][j+1][3];
        }
        if(v[i][j]=='E'){
            ++pre[i][j][2], ++pre[i][j][3]; 
        }
    }
    int maxKilledEnemies(vector<vector<char>>&v) {
        m=v.size(), n=v[0].size();
        vi(vi(vi(ll)))pre(m, vi(vi(ll))(n, vi(ll)(4, 0)));
        for(ll i=0;i<m;++i){
            for(ll j=0;j<n;++j){
                if(v[i][j]!='W'){
                    compUpLeft(v, pre, i, j);
                }
                if(v[m-i-1][n-j-1]!='W'){
                    compDownRight(v, pre, m-i-1, n-j-1);
                }
            }
        }
        ll ans=0;
        for(ll i=0;i<m;++i){
            for(ll j=0;j<n;++j){
                if(v[i][j]=='0'){
                    ans=max(ans, accumulate(begin(pre[i][j]), end(pre[i][j]), 0LL));
                }
            }
        }
        return ans;
    }
};