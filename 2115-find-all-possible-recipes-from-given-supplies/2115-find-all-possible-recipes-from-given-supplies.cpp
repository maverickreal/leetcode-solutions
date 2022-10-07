class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vector<string> findAllRecipes(vector<string>&re, vector<vector<string>>&in, vector<string>&su) {
        unordered_map<string, ll>ump;
        ll id=-1;
        for(ll i=0;i<re.size();++i){
            ump[re[i]]=++id;
            for(ll j=0;j<in[i].size();++j){
                if(ump.find(in[i][j])==ump.end()){
                    ump[in[i][j]]=++id;
                }
            }
        }
        list<ll>l;
        for(const string&s:su){
            if(ump.find(s)==ump.end()){
                ump[s]=++id;
            }
            l.pb(ump[s]);
        }
        ll n=id+1;
        vi(vi(ll))g(n);
        vi(ll)ind(n);
        for(ll i=0;i<re.size();++i){
            const ll&nd=ump[re[i]];
            for(const string&s:in[i]){
                const ll&child=ump[s];
                g[child].pb(nd);
                ++ind[nd];
            }
        }
        unordered_set<ll>ust;
        while(!l.empty()){
            ll nd=l.front();
            l.pop_front();
            ust.insert(nd);
            for(ll child:g[nd]){
                if(--ind[child]==0){
                    l.pb(child);
                }
            }
        }
        vi(string)ans;
        for(const string&s:re){
            if(ust.find(ump[s])!=ust.end()){
                ans.pb(s);
            }
        }
        return ans;
    }
};