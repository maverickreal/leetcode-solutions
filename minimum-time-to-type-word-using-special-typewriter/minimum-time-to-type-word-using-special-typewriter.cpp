class Solution {
public:
    int minTimeToType(string& s) {
        char cur = 'a';int sz = s.length(), res = 0;
        for (int i = 0;i < sz;++i) {
            char& ch = s[i];
            if (ch > cur)
                res += min(ch - cur, cur - 'a' + 'z' - ch + 1) + 1;
            else
                res += 1 + min(cur - ch, 'z' - cur + 1 + ch - 'a');
            cur = s[i];
        }
        return res;
    }
};