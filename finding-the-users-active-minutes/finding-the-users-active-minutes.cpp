class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[0] == b[0] ? a[1] < b[1] : a[0] < b[0];
    }
    vector<int> findingUsersActiveMinutes(vector<vector<int>>& v, int k) {
        int sz = v.size();
        sort(v.begin(), v.end(), cmp);
        vector<int>res(k);
        for (int i = 0;i < sz;++i) {
            int tmp = 1, j = i + 1;
            for (;j < sz && v[j][0] == v[j - 1][0];++j)
                if (v[j][1] != v[j - 1][1])
                    ++tmp;
            ++res[tmp - 1];
            i = j - 1;
        }
        for (const auto& it : v)
            for (const int& ti : it)
                cout << ti << ' ';
        return res;
    }
};