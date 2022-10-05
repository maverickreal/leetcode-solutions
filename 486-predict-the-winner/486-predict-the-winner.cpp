class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(vi(pi)))dp;
    pi func(const vi(int)&v, ll l, ll r, bool turn){
        if(l>r){
            return {0,0};
        }
        pi&ans=dp[l][r][turn];
        if(ans==pi({-1, -1})){
            pi takeLeft=func(v, l+1, r, !turn);
            (turn?takeLeft.first:takeLeft.second)+=v[l];
            pi takeRight=func(v, l, r-1, !turn);
            (turn?takeRight.first:takeRight.second)+=v[r];
            if(turn){
                ans=(takeLeft.first>takeRight.first?takeLeft:takeRight);
            }
            else{
                ans=(takeLeft.second>takeRight.second?takeLeft:takeRight);
            }
        }
        return ans;
    }
    bool PredictTheWinner(vector<int>&v) {
        n=v.size();
        dp.assign(n, vi(vi(pi))(n, vi(pi)({{-1, -1}, {-1, -1}})));
        pi p=func(v, 0, n-1, true);
        return p.first>=p.second;
    }
};