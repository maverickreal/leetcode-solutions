class Solution {
    typedef long long ll;
public:
    int findMiddleIndex(vector<int>& pre) {
        ll sz = pre.size();
        for (int i = 1;i < sz;++i)
            pre[i] += pre[i - 1];
        for (int i = 0;i < sz;++i) {
            ll l = (i ? pre[i - 1] : 0);
            ll r = pre.back() - pre[i];
            if (l == r)
                return i;
        }
        return -1;
    }
};