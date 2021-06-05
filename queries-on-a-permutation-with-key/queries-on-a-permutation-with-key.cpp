class Solution {
public:
    vector<int> processQueries(vector<int>& q, int m) {
        int sz = q.size();
        vector<int>res(sz);
        list<int>l;
        for (int i = 1;i <= m;++i)
            l.push_back(i);
        for (int i = 0;i < sz;++i) {
            int pos = 0;
            for (auto it = l.begin(); it != l.end();++it) {
                if (*it == q[i]) {
                    res[i] = pos;
                    l.push_front(*it);
                    l.erase(it);
                    break;
                }
                ++pos;
            }
        }
        return res;
    }
};