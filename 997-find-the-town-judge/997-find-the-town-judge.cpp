class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    int findJudge(int n, vector<vector<int>>&v) {
        list<ll>l;
        vi(vi(bool))trust(n+1, vi(bool)(n+1));
        for(auto it:v){
            trust[it[0]][it[1]]=true;
        }
        for(ll i=1;i<=n;++i){
            l.pb(i);
        }
        while(l.size()>1){
            ll b=l.back();
            l.pop_back();
            ll a=l.back();
            l.pop_back();
            if(trust[a][b]){
                l.pb(b);
            }
            else{
                l.pb(a);
            }
        }
        if(l.empty()){
            return -1;
        }
        ll it=l.back();
        for(ll i=1;i<=n;++i){
            if((i!=it && !trust[i][it]) || trust[it][i]){
                return -1;
            }
        }
        return it;
    }
};