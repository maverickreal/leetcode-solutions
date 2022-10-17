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
    int minCost(vector<vector<int>>&v) {
        ll m=v.size(), n=v[0].size();
        vi(vi(ll))cost(m, vi(ll)(n, LLONG_MAX));
        priority_queue<vi(ll), vi(vi(ll)), cmp>pq;
        pq.push({m-1, n-1, 0});
        cost[m-1][n-1]=0;
        while(!pq.empty()){
            auto nd=pq.top();
            pq.pop();
            if(nd[0]==0 && nd[1]==0){
                break;
            }
            if(cost[nd[0]][nd[1]]<nd[2]){
                continue;
            }
            if(nd[0]>0){
                ll res=nd[2]+(v[nd[0]-1][nd[1]]!=3);
                if(res<cost[nd[0]-1][nd[1]]){
                    cost[nd[0]-1][nd[1]]=res;
                    pq.push({nd[0]-1, nd[1], res});
                }
            }
            if(nd[1]>0){
                ll res=nd[2]+(v[nd[0]][nd[1]-1]!=1);
                if(res<cost[nd[0]][nd[1]-1]){
                    cost[nd[0]][nd[1]-1]=res;
                    pq.push({nd[0], nd[1]-1, res});
                }
            }
            if(nd[0]<m-1){
                ll res=nd[2]+(v[nd[0]+1][nd[1]]!=4);
                if(res<cost[nd[0]+1][nd[1]]){
                    cost[nd[0]+1][nd[1]]=res;
                    pq.push({nd[0]+1, nd[1], res});
                }
            }
            if(nd[1]<n-1){
                ll res=nd[2]+(v[nd[0]][nd[1]+1]!=2);
                if(res<cost[nd[0]][nd[1]+1]){
                    cost[nd[0]][nd[1]+1]=res;
                    pq.push({nd[0], nd[1]+1, res});
                }
            }
        }
        return cost[0][0];
    }
};