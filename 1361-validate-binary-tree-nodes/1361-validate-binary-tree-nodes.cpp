class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll count(ll nd, const vi(int)&lc, const vi(int)&rc){
        if(nd==-1){
            return 0;
        }
        return 1+count(lc[nd], lc, rc)+count(rc[nd], lc, rc);
    }
    bool validateBinaryTreeNodes(int n, vector<int>&lc, vector<int>&rc) {
        vi(ll)ind(n);
        for(ll i=0;i<n;++i){
            if(lc[i]>-1){
                ++ind[lc[i]];
                if(ind[lc[i]]>1){
                    return false;
                }
            }
            if(rc[i]>-1){
                ++ind[rc[i]];
                if(ind[rc[i]]>1){
                    return false;
                }
            }
        }
        ll root=-1;
        for(ll i=0;i<n;++i){
            if(ind[i]>1){
                return false;
            }
            if(ind[i]==0){
                if(root==-1){
                    root=i;
                }
                else{
                    return false;
                }
            }
        }
        return (count(root, lc, rc)==n);
    }
};