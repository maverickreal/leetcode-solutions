class Solution {
typedef long long ll;
typedef long double ld;
typedef pair<ll, ld> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    class cmp{
    public:
        bool operator()(const pi&a, const pi&b){
            return (a.second<b.second);
        }
    };
    double maxProbability(int n, vector<vector<int>>&e, vector<double>&sp, int src, int end) {
        vi(vi(pi))g(n);
        for(ll i=0;i<e.size();++i){
            g[e[i][0]].pb({e[i][1], sp[i]});
            g[e[i][1]].pb({e[i][0], sp[i]});
        }
        vi(ld)d(n, 0);
        priority_queue<pi, vi(pi), cmp>pq;
        pq.push({src, 1});
        d[src]=1;
        while(!pq.empty()){
            pi ndp=pq.top();
            pq.pop();
            if(d[ndp.first]!=ndp.second){
                continue;
            }
             for(pi chp:g[ndp.first]){
                if(ndp.second*chp.second>d[chp.first]){
                    d[chp.first]=ndp.second*chp.second;
                    pq.push({chp.first, d[chp.first]});
                }
            }
        }
        return d[end];
    }
};