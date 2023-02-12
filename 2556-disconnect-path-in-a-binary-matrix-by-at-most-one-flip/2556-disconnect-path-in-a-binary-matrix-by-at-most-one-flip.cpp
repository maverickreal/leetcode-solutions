class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9+7;
const char nl = '\n';
    
ll m,n;

bool dfs(vi(vi(int))&g, ll i, ll j){
    if(i<0 || j<0 || i>=m || j>=n || !g[i][j]){
        return 0;
    }
    g[i][j]=0;
    if(i==m-1 && j==n-1){
        return 1;
    }
    return (dfs(g, i, j+1) || dfs(g, i+1, j));
}

bool isPossibleToCutPath(vector<vector<int>>&g) {
    m=g.size(), n=g[0].size();
    bool res = dfs(g, 0, 0);
    if(!res){
        return 1;
    }
    g[0][0]=g[m-1][n-1]=1;
    return !dfs(g, 0, 0);
}
};