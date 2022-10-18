class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    class cmp{
    public:
        bool operator()(const pi&a, const pi&b){
            return a.second>b.second;
        }
    };
    int minimumTime(int n, vector<vector<int>>&e, vector<int>&t) {
        priority_queue<pi, vi(pi), cmp>pq;
        vi(ll)ind(n, 0);
        vi(vi(ll))g(n);
        for(const auto&edge:e){
            ++ind[edge[1]-1];
            g[edge[0]-1].pb(edge[1]-1);
        }
        ll mx=0;
        for(ll i=0;i<n;++i){
            if(!ind[i]){
                pq.push({i, t[i]});
            }
        }
        while(!pq.empty()){
            pi p=pq.top();
            pq.pop();
            mx=max(mx, p.second);
            for(const ll&child:g[p.first]){
                if(--ind[child]==0){
                    pq.push({child, p.second+t[child]});
                }
            }
        }
        return mx;
    }
};