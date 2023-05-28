class Solution {
public:
    typedef long long ll;
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>&v) {
        ll m=v.size(), n=v[0].size();
        vector<vector<int>>ans(m, vector<int>(n));
        for(ll i=0; i<m; ++i){
            for(ll j=0; j<n; ++j){
                bitset<51>tl(0);
                bitset<51>br(0);
                for(ll dec=1; i-dec>-1 && j-dec>-1; ++dec){
                    tl[v[i-dec][j-dec]]=1;
                }
                for(ll inc=1; i+inc<m && j+inc<n; ++inc){
                    br[v[i+inc][j+inc]]=1;
                }
                ans[i][j]=abs(ll(tl.count()-br.count()));
            }
        }
        return ans;
    }
};