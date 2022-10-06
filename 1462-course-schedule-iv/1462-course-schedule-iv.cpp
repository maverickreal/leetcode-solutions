class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>&e, vector<vector<int>>&q) {
        vi(vi(ll))g(n);
        vi(ll)ind(n);
        for(auto edge:e){
            ind[edge[1]]++;
            g[edge[0]].pb(edge[1]);
        }
        vi(unordered_set<ll>)pre(n);
        list<ll>l;
        for(ll i=0;i<n;++i){
            if(!ind[i]){
                l.pb(i);
            }
        }
        while(!l.empty()){
            ll nd=l.front();
            l.pop_front();
            for(ll child:g[nd]){
                pre[child].insert(nd);
                for(ll dep:pre[nd]){
                    pre[child].insert(dep);
                }
                if(--ind[child]==0){
                    l.pb(child);
                }
            }
        }
        vi(bool)ans(q.size());
        for(ll i=0;i<q.size();++i){
            ans[i]=pre[q[i][1]].find(q[i][0])!=pre[q[i][1]].end();
        }
        return ans;
    }
};