class Solution {
typedef long long ll;
typedef pair<string, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    static bool cmp(const pi&a, const pi&b){
        return (a.second==b.second?a.first<b.first:a.second<b.second);
    }
    vector<string> watchedVideosByFriends(vector<vector<string>>&vid, vector<vector<int>>&f, int id, int level) {
        vi(bool)vis(f.size());
        list<ll>l={id};
        vis[id]=true;
        for(ll k=0;k<level;++k){
            ll sz=l.size();
            while(sz--){
                ll nd=l.front();
                l.pop_front();
                // if(vis[nd]){
                //     continue;
                // }
                vis[nd]=true;
                for(ll child:f[nd]){
                    if(!vis[child]){
                        l.pb(child);
                        vis[child]=true;
                    }
                }
            }
        }
        unordered_map<string, ll>ump;
        for(ll nd:l){
            //if(!vis[nd]){
                for(const string&v:vid[nd]){
                    ++ump[v];
                }
            //}
        }
        vi(pi)v(begin(ump), end(ump));
        sort(begin(v), end(v), cmp);
        vi(string)res(v.size());
        for(ll i=0;i<v.size();++i){
            res[i]=v[i].first;
        }
        return res;
    }
};