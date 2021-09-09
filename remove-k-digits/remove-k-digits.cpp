class Solution {
public:
    string removeKdigits(string& s, int k) {
        string res;
        const int sz = s.length(), K = k;
        if (sz == 1 || k>=sz)
            return "0";
        int i = 0;
        for (;i < sz && k>0 && res.size() < sz - K;) {
            int mn = i;
            for (int j = i + 1;j <= min(sz - 1, i + k);++j)
                if (s[j] < s[mn])
                    mn = j;
            res.push_back(s[mn]);
            k -= mn - i;
            i = mn + 1;
        }
        if (res.size() < sz - K)
            res.append(s.substr(i, sz - i));
        reverse(res.begin(), res.end());
        while (res.size() > 1 && res.back() == '0')
            res.pop_back();
        reverse(res.begin(), res.end());
        return res;
    }
};