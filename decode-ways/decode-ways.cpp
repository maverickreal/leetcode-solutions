class Solution {
public:
    int numDecodings(string& s) {
        if (s.front() == '0')
            return 0;
        int sz = s.length();
        vector<int>v(sz);
        v.front() = 1;
        for (int i = 1;i < sz;++i) {
            const char& ch = s[i];
            if (ch == '0') {
                if (s[i - 1] != '1' && s[i - 1] != '2')
                    return 0;
                v[i] = (i > 1 ? v[i - 2] : 1);
                continue;
            }
            v[i] = v[i - 1];
            if (s[i - 1] != '0') {
                int num = ((s[i - 1] - '0') * 10) + (ch - '0');
                //cout << num;
                if (num < 27)
                    v[i] += (i > 1 ? v[i - 2] : 1);
            }
        }
        // for (int& i : v)
        //     cout << i << "  ";
        return v.back();
    }
};