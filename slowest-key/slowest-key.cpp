class Solution {
public:
    char slowestKey(vector<int>& v, string& s) {
        int sz = s.length(), resDur = v.front();
        char resKey = s.front();
        for (int i = 1;i < sz;++i) {
            int curDur = v[i] - v[i - 1];
            if (curDur > resDur)
                resDur = curDur, resKey = s[i];
            else if (resDur == curDur)
                resKey = max(resKey, s[i]);
        }
        return resKey;
    }
};