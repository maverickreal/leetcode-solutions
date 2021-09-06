class Solution {
public:
    string orderlyQueue(string& s, int k) {
        int sz = s.length();
        if (!k) return s;
        if (k > 1) {
            sort(s.begin(), s.end());
            return s;
        }
        list<char>l(s.begin(), s.end());
        for (int i = 0;i < sz;++i) {
            l.push_back(l.front());
            l.pop_front();
            s = min(s, string(l.begin(), l.end()));
        }
        return s;
    }
};