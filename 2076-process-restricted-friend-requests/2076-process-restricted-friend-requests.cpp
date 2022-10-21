class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    class dsu{
    public:
        vi(ll)par, size;
        dsu(ll n){
            par.assign(n, 0), size.assign(n, 1);
            iota(begin(par), end(par), 0);
        }
        ll find(ll n){
            if(par[n]==n){
                return n;
            }
            return (par[n]=find(par[n]));
        }
        void merge(ll a, ll b){
            a=find(a), b=find(b);
            if(a==b){
                return;
            }
            if(size[a]<size[b]){
                a+=b, b=a-b, a-=b;
            }
            par[b]=a;
            size[a]+=size[b];
        }
    };
    vector<bool> friendRequests(int n, vector<vector<int>>&r, vector<vector<int>>&q){
        dsu f(n);
        vi(bool)ans(q.size(), 1);
        for(ll i=0;i<q.size();++i){
            if(f.find(q[i][0])==f.find(q[i][1])){
                continue;
            }
            for(const auto&e:r){
                if((f.find(e[0])==f.find(q[i][0]) && f.find(e[1])==f.find(q[i][1])) || (f.find(e[1])==f.find(q[i][0]) && f.find(e[0])==f.find(q[i][1]))){
                    ans[i]=0;
                    break;
                }
            }
            if(ans[i]){
                f.merge(q[i][0], q[i][1]);
            }
        }
        return ans;
    }
};