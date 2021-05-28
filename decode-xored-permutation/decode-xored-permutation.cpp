class Solution {
public:
    vector<int> decode(vector<int>& v) {
        int n = v.size() + 1, xo = 0;
        for (int i = 1;i <= n;++i)
            xo ^= i;
        for (int i = 1;i < n - 1;i+=2)
            xo^= v[i];
        vector<int>res(n);
        res[0] = xo;
        for (int i = 0;i < n - 1;++i)
            res[i + 1] = v[i] ^ res[i];
        return res;
    }
};