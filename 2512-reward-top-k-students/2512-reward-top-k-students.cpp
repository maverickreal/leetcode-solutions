class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
public:
ll n;
unordered_set<string>pfust, nfust;
class cmp{
    public:
    bool operator()(const pi&a, const pi&b){
        return (a.first==b.first?a.second>b.second:a.first<b.first);
    }
};
ll getScore(const string&s){
    ll sz=s.size(), ans=0;
    for(ll i=0;i<sz;++i){
        ll j=i;
        string word;
        for(;j<sz && s[j]!=' ';++j){
            word.pb(s[j]);
        }
        if(pfust.find(word)!=pfust.end()){
            ans+=3;
        }
        if(nfust.find(word)!=nfust.end()){
            --ans;
        }
        i=j;
    }
    return ans;
}
    vector<int> topStudents(vector<string>&pf, vector<string>&nf, vector<string>&r, vector<int>&sid, int k) {
        n=sid.size();
        for(const string&s:pf){
            pfust.insert(s);
        }
        for(const string&s:nf){
            nfust.insert(s);
        }
        priority_queue<pi, vi(pi), cmp>pq;
        for(ll i=0;i<n;++i){
            pq.push({getScore(r[i]), sid[i]});
        }
        vi(int)ans(k);
        for(ll pos=0;pos<k;++pos){
            ans[pos]=pq.top().second;
            pq.pop();
        }
        return ans;
    }
};