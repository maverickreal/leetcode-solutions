class Solution {
public:
    vector<bool> camelMatch(vector<string>& v, string& s) {
        int sz = v.size();
        vector<bool>res(sz);
        for (int i = 0;i < sz;++i) {
            int ti = 0;
            bool fl = true;
            for (char& ch : v[i]) {
                if (ch >= 97 && ch <= 122) {
                    if (ti < s.length() && s[ti] == ch)
                        ++ti;
                    continue;
                }
                if (ti < s.length() && ch == s[ti]) {
                    ++ti;
                    continue;
                }
                fl = false;
                break;
            }
            if (ti == s.length() && fl)
                res[i] = true;
        }
        return res;
    }
};