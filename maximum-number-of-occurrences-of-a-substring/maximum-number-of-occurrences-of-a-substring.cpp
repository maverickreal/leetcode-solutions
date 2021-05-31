class Solution {
public:
    int maxFreq(string& s, int mx, int mns, int mxs) {
        int sz = s.length(), res = 0;
        unordered_map<string, int>ump;
        for (int i = 0;i < sz;++i) {
            string tmp;
            unordered_set<char>ust;
            for (int j = i;j < sz && j - i + 1 <= mxs;++j) {
                ust.insert(s[j]);
                if (ust.size() > mx)
                    break;
                tmp.push_back(s[j]);
                if (j - i + 1 < mns)
                    continue;
                res = max(res, ++ump[tmp]);
            }
        }
        return res;
    }
};