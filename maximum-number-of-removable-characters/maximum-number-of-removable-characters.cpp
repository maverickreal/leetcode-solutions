class Solution {
public:
    int sz, szs, szp, res;
    bool func(string s, const string& p, const vector<int>& v, int k) {
        for (int i = 0;i <= k;++i)
            s[v[i]] = '0';
        int j = 0;
        for (int i = 0;i < szs && j < szp;++i)
            if (s[i] == p[j])
                ++j;
        return j == szp;
    }
    int maximumRemovals(string& s, string& p, vector<int>& v) {
        szs = s.length(), szp = p.length(), sz = v.size(), res = 0;
        int i = 0, j = sz - 1;
        while (i <= j) {
            int m = (i + j) >> 1;
            if (func(s, p, v, m))
                res = i = m + 1;
            else
                j = m - 1;
        }
        return res;
    }
};