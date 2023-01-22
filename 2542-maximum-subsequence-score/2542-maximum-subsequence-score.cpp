
class Solution {
    typedef long long ll;
    #define vi(x) vector<x>
    typedef pair<ll, ll> pi;
    #define pb push_back
public:
    vi(pi)arr;
    ll k;
    void getArr(const vi(int)&u, const vi(int)&v){ // get the sum of the k largest elements from u
        ll sz=u.size();
        for(ll i=0;i<sz;++i){
            arr.pb({u[i], v[i]});
        }
        sort(begin(arr), end(arr),
        [](const pi&a, const pi&b){
        return (a.second==b.second?a.first>b.first:a.second>b.second);
        });
        priority_queue<ll, vi(ll), greater<int>>pq;
        for(ll i=0, sum=0;i<arr.size();++i){
            const auto&[uit, vit]=arr[i];
            sum+=uit;
            pq.push(uit);
            if(pq.size()>k){
                sum-=pq.top();
                pq.pop();
            }
            arr[i].first=i < k-1 ? 0 : sum; // there are insufficient numbers 
        }
    }
    ll func(ll x){ // Binary Search
        ll l=0, r=arr.size()-1, ans=0;
        while(l<=r){
            ll m=l+((r-l)>>1);
            const auto&[val, it]=arr[m];
            if(it<x){
                r=m-1;
            }
            else{
                ans=val, l=m+1;
            }
        }
        return ans;
    }
    long long maxScore(vector<int>&u, vector<int>&v, int K) {
        k=K, getArr(u, v); // construct a prefix
        ll ans=0;
        for(ll minItem:v){
            ans=max(ans, minItem*func(minItem));
        }
        return ans;
    }
};