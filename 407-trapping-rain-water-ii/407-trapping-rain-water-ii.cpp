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
        bool operator()(const vi(ll)&a, const vi(ll)&b){
            return (a[2]>b[2]);
        }
    };
    int trapRainWater(vector<vector<int>>&v) {
        ll res=0, m=v.size(), n=v[0].size();
        vi(vi(bool))vis(m, vi(bool)(n, false));
        vi(vi(ll))dirs={{1, 0}, {0, 1}, {-1, 0}, {0, -1}};
        priority_queue<vi(ll), vi(vi(ll)), cmp>pq;
        for(ll i=0;i<n;++i){
            vis[0][i]=vis[m-1][i]=true;
            pq.push({0, i, v[0][i]}), pq.push({m-1, i, v[m-1][i]});
        }
        for(ll i=0;i<m;++i){
            vis[i][0]=vis[i][n-1]=true;
            pq.push({i, 0, v[i][0]}), pq.push({i, n-1, v[i][n-1]});
        }
        while(!pq.empty()){
            vi(ll)it=pq.top();
            pq.pop();
            for(vi(ll) dir:dirs){
                ll i=it[0]+dir[0], j=it[1]+dir[1];
                if(i<0 || i>=m || j<0 || j>=n || vis[i][j]){
                    continue;
                }
                vis[i][j]=true;
                res+=max(0LL, it[2]-v[i][j]);
                pq.push({i, j, max(ll(v[i][j]), it[2])});
            }
        }
        return res;
    }
};