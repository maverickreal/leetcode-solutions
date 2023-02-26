class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
    
class cmp{
    public:
    bool operator()(const vi(ll)&a, const vi(ll)&b){
        if(a[2]!=b[2]){
            return (a[2]>b[2]);
        }
        if(a[1]!=b[1]){
            return (a[1]<b[1]);
        }
        return (a[0]<b[0]);
    }
};
    
ll m, n;

bool exists(const ll&i, const ll&j){
    return (i>-1 && j>-1 && i<m && j<n);
}

int minimumTime(vector<vector<int>>&v) {
    if(v[0][1]>1 && v[1][0]>1){
        return -1;
    }
    m=v.size(), n=v[0].size();
    vi(vi(ll))dirs={{0, -1}, {-1, 0}, {0, 1}, {1, 0}};
    vi(vi(bool))vis(m, vi(bool)(n, 0));
    priority_queue<vi(ll), vi(vi(ll)), cmp>pq;
    pq.push({0, 0, 0});
    vis[0][0]=1;
    while(!pq.empty()){
        vi(ll)it=pq.top();
        pq.pop();
        if(it[0]==m-1 && it[1]==n-1){
            return it[2];
        }
        // if(!exists(it[0], it[1]) || vis[it[0]][it[1]]){
        //     continue;
        // }
        // vis[it[0]][it[1]]=1;
        for(const vi(ll)&dir:dirs){
            ll x=it[0]+dir[0], y=it[1]+dir[1];
            if(!exists(x, y) || vis[x][y]){
                continue;
            }
            vis[x][y]=1;
            if(it[2]+1>=v[x][y]){
                pq.push({x, y, it[2]+1});
            }
            else{
                bool inc=!((v[x][y]-it[2])&1);
                pq.push({x, y, v[x][y]+inc});
            }
        }
    }
    return -1;
}
};