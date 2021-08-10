class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& v, int k) {
        int sz = v.size();
        vector<int>res(sz + 1);
        for (int i = 0;i < sz;++i) {
            int mx = v[i];
            for (int j = 1;j <= min(k, i + 1);++j) {
                mx = max(mx, v[i+1-j]);
                res[i+1] = max(res[i+1], (mx * j) + res[i-j+1]);
            }
        }
        for (int& i : res)
            cout << i << ' ';

        return res.back();
    }
};