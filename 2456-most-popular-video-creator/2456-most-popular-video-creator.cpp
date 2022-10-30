class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    static bool cmp(const pair<string, pi>&a, const pair<string, pi>&b){
        return a.second.first>b.second.first;
    }
    vector<vector<string>> mostPopularCreator(vector<string>&c, vector<string>&ids, vector<int>&v) {
        ll n=c.size();
        unordered_map<string, pi>ump;
        for(ll i=0;i<n;++i){
            const string&name=c[i];
            const string&id=ids[i];
            const ll&views=v[i];
            if(ump.find(name)==ump.end()){
                ump[name]={views, i};
            }
            else{
                ump[name].first+=views;
                if(v[ump[name].second]<v[i] || (v[ump[name].second]==v[i] && ids[i].compare(ids[ump[name].second])==-1)){
                    ump[name].second=i;
                }
            }
        }
        vi(vi(string))ans;
        vector<pair<string, pi>>arr(begin(ump), end(ump));
        sort(begin(arr), end(arr), cmp);
        for(ll in=0;in<arr.size() && arr[in].second.first==arr[0].second.first;++in){
            ans.pb({arr[in].first, ids[arr[in].second.second]});
        }
        return ans;
    }
};