class Solution {
public:
    string longestWord(vector<string>& v) {
        int sz = v.size();
        unordered_set<string>ust(v.begin(), v.end());
        string res = "";
        for (int i = 0;i < sz;++i) {
            int szs = v[i].length(), j = 0;
            string tmp = "";
            for (;j < szs;++j) {
                tmp.push_back(v[i][j]);
                if (ust.find(tmp) == ust.end())
                    break;
            }
            if (j == szs && (szs > res.length() || (szs == res.length() && lexicographical_compare(v[i].begin(), v[i].end(), res.begin(), res.end()))))
                res = v[i];
            cout << res << ' ';
        }
        return res;
    }
};