class Solution {
    typedef long long ll;
public:
    vector<int> productExceptSelf(vector<int>& v) {
        ll sz = v.size();
        vector<ll>pre(sz), post(sz);
        vector<int>res(sz);
        pre.front() = v.front();
        post.back() = v.back();
        for (ll i = 1;i < sz;++i)
            pre[i] = v[i] * pre[i - 1], post[sz - i - 1] = v[sz - i - 1] * post[sz - i];
        for (int i = 0;i < sz;++i) {
            res[i] = 1;
            if (i)
                res[i] *= pre[i - 1];
            if (i < sz-1)
                res[i] *= post[i + 1];
        }
        return res;
    }
};