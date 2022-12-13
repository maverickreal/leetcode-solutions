class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vector<int> countPairs(int n, vector<vector<int>>&e, vector<int>&queries) {
        vi(ll)deg(n);
        unordered_map<ll, unordered_map<ll, ll>>ump;
        for(const auto&edge:e){
            ll u=edge[0]-1, v=edge[1]-1;
            if(u>v){
                u+=v, v=u-v, u-=v;
            }
            ++ump[u][v], ++deg[u], ++deg[v];
        }
        vi(ll)degCpy=deg;
        sort(begin(deg), end(deg));
        vi(int)res(queries.size());
        for(ll k=0;k<queries.size();++k){
            const int&q=queries[k];
            for(ll l=0, r=n-1;l<r;){
                if(deg[l]+deg[r]>q){
                    res[k]+=r-l, --r;
                }
                else{
                    ++l;
                }
            }
            for(ll i=0;i<n;++i){
                for(const auto&[j, m]:ump[i]){
                    res[k]-=(degCpy[i]+degCpy[j]>q) && (degCpy[i]+degCpy[j]-ump[i][j]<=q);
                }
            }
        }
        return res;
    }
};