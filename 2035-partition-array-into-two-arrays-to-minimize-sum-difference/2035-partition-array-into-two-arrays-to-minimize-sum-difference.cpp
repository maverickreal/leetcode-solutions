class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n, tot, ans=LLONG_MAX;
    ll bs(const vi(ll)&v, ll x){
        // for(auto it:v){
        //     cout<<it<<' ';
        // }
        // cout<<nl;
        if(x>=v.back()){
            return v.back();
        }
        if(x<=v[0]){
            return v[0];
        }
        ll l=0, r=v.size()-1, ans=-1;
        while(l<=r){
            ll m=l+((r-l)>>1);
            if(v[m]>=x){
                ans=m, r=m-1;
            }
            else{
                l=m+1;
            }
        }
        if(ans>0 && abs(x-v[ans-1])<abs(x-v[ans])){
            --ans;
        }
        return v[ans];
    }
    void func(const vi(int)&v, ll in, ll cnt, ll cur, vi(vi(ll))&ump){
        if(in==v.size()){
            ump[cnt].pb(cur);
            return;
        }
        func(v, in+1, cnt, cur, ump), func(v, in+1, cnt+1, cur+v[in], ump);
    }
    void search(const vi(int)&v, ll in, ll cnt, ll cur, vi(vi(ll))&ump){
        if(in==n/2){
            ll formed=cur+bs(ump[n/2-cnt], tot/2-cur);
            //cout<<in<<' '<<cnt<<' '<<cur<<' '<<(n/2-cnt)<<' '<<(tot/2-cur)<<' '<<formed<<nl;
            ans=min(ans, abs(tot-2*formed));
            return;
        }
        search(v, in+1, cnt, cur, ump), search(v, in+1, cnt+1, cur+v[in], ump);
    }
    int minimumDifference(vector<int>&v) {
        n=v.size(), tot=accumulate(begin(v), end(v), 0LL);
        vi(vi(ll))ump((n>>1)+1);
        func(v, n>>1, 0, 0, ump);
        for(auto&it:ump){
            sort(begin(it), end(it));
        }
        search(v, 0, 0, 0, ump);
        return ans;
    }
};