class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    vi(vi(pi))dp;
    pi func(const vi(int)&v, ll in, bool turn){
        if(in>=n){
            return {0, 0};
        }
        pi&ans=dp[in][turn];
        if(ans==pi({LLONG_MAX, LLONG_MAX})){
            pi one={LLONG_MIN, LLONG_MIN};
            if(in<n){
                one=func(v, in+1, !turn);
                (turn?one.first:one.second)+=v[in];
            }
            pi two={LLONG_MIN, LLONG_MIN};
            if(in<n-1){
                two=func(v, in+2, !turn);
                (turn?two.first:two.second)+=v[in]+v[in+1];
            }
            pi three={LLONG_MIN, LLONG_MIN};
            if(in<n-2){
                three=func(v, in+3, !turn);
                (turn?three.first:three.second)+=v[in]+v[in+1]+v[in+2];
            }
            if(turn){
                ll mx=max({one.first, two.first, three.first});
                if(one.first==mx){
                    ans=one;
                }
                else if(two.first==mx){
                    ans=two;
                }
                else{
                    ans=three;
                }
            }
            else{
                ll mx=max({one.second, two.second, three.second});
                if(one.second==mx){
                    ans=one;
                }
                else if(two.second==mx){
                    ans=two;
                }
                else{
                    ans=three;
                }
            }
        }
        //cout<<in<<' '<<turn<<' '<<ans.first<<' '<<ans.second<<nl;
        return ans;
    }
    string stoneGameIII(vector<int>&v) {
        n=v.size();
        dp.assign(n+1, vi(pi)(2, {LLONG_MAX, LLONG_MAX}));
        pi ans=func(v, 0, true);
        if(ans.first>ans.second){
            return "Alice";
        }
        if(ans.first<ans.second){
            return "Bob";
        }
        return "Tie";
    }
};