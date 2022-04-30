class Solution {
public:
typedef long long ll;
#define endl '\n'
const ll mod = 1e9 + 7;

int minimumAverageDifference(vector<int>& v) {
    const ll sz = v.size();
    vector<ll>preSum(sz);
    preSum.front()=v.front();
    for (ll i = 1;i < sz;++i)
        preSum[i] = v[i] +  preSum[i - 1];
    ll res=LLONG_MAX, in=-1;
    for (ll i = 0;i < sz;++i) {
        ll left = preSum[i] / (i + 1);
        ll right = i==sz-1?0:(preSum[sz - 1] - preSum[i] )/ (sz - i - 1);
        ll tmp=ll(round(abs(left - right)));
        if(tmp<res){
            res=tmp;
            in=i;
        }
    }
    return in;
}
};