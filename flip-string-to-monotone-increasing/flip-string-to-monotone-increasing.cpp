class Solution {
public:
    int minFlipsMonoIncr(const string& s) {
        int sz = s.length();
        vector<int>pre(sz);
        pre.front() = s.front() == '1';
        for (int i = 1;i < sz;++i)
            pre[i] = pre[i - 1] + (s[i] == '1');
        int res = pre.back();
        for (int i = 1;i < sz;++i)
            res = min(res, (int)((pre[i - 1] << 1) - pre.back() + sz - i));
        /* for (int& i : pre)
            cout << i << ' ';
        cout << '\n' << res; */
        return min(res, sz - pre.back());
    }
};