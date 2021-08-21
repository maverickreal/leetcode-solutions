class Solution {
#define ll long long
public:
    ll maxMatrixSum(vector<vector<int>>& v) {
        ll res = 0, mn = INT_MIN, mx = INT_MAX, cnt = 0;
        bool fl = 0;
        for (auto& it : v) {
            for (int& ti : it) {
                res += abs(ti);
                if (ti == 0)
                    fl = true;
                if (ti < 0) {
                    ++cnt;
                    mn = max(mn, (ll)ti);
                }
                if (ti > 0)
                    mx = min(mx, (ll)ti);
            }
        }
        if ((cnt & 1) && !fl && mn != INT_MIN)
            res -= min(abs(mn), mx)*2;
        return res;
    }
};