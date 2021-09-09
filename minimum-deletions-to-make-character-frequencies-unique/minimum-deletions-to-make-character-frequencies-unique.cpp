class Solution {
public:
    int minDeletions(string& s) {
        int sz = s.length();
        vector<int>v(26);
        for (char ch : s)
            ++v[ch - 'a'];
        sort(v.begin(), v.end(), greater<int>());
        while (!v.back())
            v.pop_back();
        int res = 0, i = 0;
        while (++i < v.size()) {
            if (!v[i - 1])
                break;
            if (v[i] >= v[i - 1]) {
                res += v[i] - v[i - 1] + 1;
                v[i] = v[i - 1] - 1;
            }
        }
        if (i < sz)
            res += accumulate(v.begin() + i, v.end(), 0);
        return res;
    }
};