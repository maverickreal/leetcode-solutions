class Solution {
typedef long long ll;
typedef long double ld;
typedef pair<ll, ld> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(pi)par;
    vi(ll)size;
    pi find(ll n){
        pi cur=par[n];
        if(cur.first==n){
            return cur;
        }
        pi rec=find(par[n].first);
        par[n]={rec.first, rec.second*cur.second};
        return par[n];
    }
    void merge(ll a, ll b, ld wt){
        pi x=find(a), y=find(b);
        if(x.first==y.first){
            return;
        }
        if(size[x.first]<size[y.first]){
            pi tmp=x;
            x=y;
            y=tmp;
            wt=ld(1)/wt;
        }
        par[y.first]={x.first, (x.second*wt)/y.second};
        size[x.first]+=size[y.first];
    }
    ld getAns(ll a, ll b){
        if(a<1 || b<1){
            return -1;
        }
        pi x=find(a), y=find(b);
        if(x.first!=y.first){
            return -1;
        }
        return (y.second/x.second);
    }
    unordered_map<string, ll>ump;
    vector<double> calcEquation(vector<vector<string>>&eq, vector<double>&vals, vector<vector<string>>&qs) {
        ll id=1;
        for(auto it:eq){
            if(ump.find(it[0])==ump.end()){
                ump[it[0]]=id++;
            }
            if(ump.find(it[1])==ump.end()){
                ump[it[1]]=id++;
            }
        }
        par.resize(id), size.assign(id, 1);
        for(ll i=0;i<id;++i){
            par[i]={i, 1};
        }
        for(ll i=0;i<vals.size();++i){
            merge(ump[eq[i][0]], ump[eq[i][1]], vals[i]);
        }
        vi(double)ans;
        for(ll i=0;i<qs.size();++i){
            ans.pb(getAns(ump[qs[i][0]], ump[qs[i][1]]));
        }
        return ans;
    }
};