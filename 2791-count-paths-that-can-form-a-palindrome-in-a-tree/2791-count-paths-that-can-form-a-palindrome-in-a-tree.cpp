class Solution {
public:
    typedef long long ll;
    vector<vector<ll>>g;
    ll n;
    vector<ll>bm;
    unordered_map<ll, ll>ump;
    void dfs(const string&str, ll nd, ll curBm){
        bm[nd] = curBm;
        ++ump[curBm];
        for(const ll&child : g[nd]){
            dfs(str, child, curBm^(1<<(str[child]-'a')));
        }
    }
    long long countPalindromePaths(vector<int>&par, string&str) {
        n = par.size();
        ll ans = 0;
        g.resize(n), bm.assign(n, 0);
        for(ll i=1; i<n; ++i){
            g[par[i]].push_back(i);
        }
        dfs(str, 0, 0);
        for(ll i=0; i<n; ++i){
            ll curBm = bm[i];
            ans+=ump[curBm]-1;
            for(ll j=0; j<26; ++j){
                curBm^=1<<j;
                ans+=ump[curBm];
                curBm^=1<<j;
            }
        }
        return ans/2;
    };
};