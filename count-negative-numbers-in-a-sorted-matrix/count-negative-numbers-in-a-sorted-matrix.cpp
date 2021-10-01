class Solution {
public:
    typedef long long ll;
    int countNegatives(vector<vector<int>>& v) {
        ll i = 0, j = v[0].size() - 1, res = 0;
        for (int r = 0;r < v.size(); ++r) {
            vector<int>& it = v[r];
           // cout << res << ' ';
            ll s = i, e = j, m = s + ((e - s) >> 1);
            while (s < e) {
                m = s + ((e - s) >> 1);
                if (it[m] > -1)
                    s = m + 1;
                else
                    e = m;
            }
            m = s + ((e - s) >> 1);
            if (it[m] > -1) {
               // cout << r << ' ' << s << ' ' << e << '\n';
                continue;
            }
            res += (j - m + 1) * (v.size() - r);
            j = m - 1;
            if (j < 0)
                break;
        }
        return res;
    }
};