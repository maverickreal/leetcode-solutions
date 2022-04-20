class Solution {
public:
    typedef long long ll;
    bool isBipartite(const vector<vector<int>>& ump) {
        unordered_set<ll>a, b;
        for (int i = 0;i < ump.size();++i) {
            if (a.find(i) != a.end() || b.find(i) != b.end()) continue;
            queue<ll>q;
            q.push(i);
            a.insert(i);
            while (!q.empty()) {
                auto p = q.front();
                q.pop();
                bool ina = (a.find(p) != a.end());
                for (const auto& it : ump[p]) {
                    if ((ina && a.find(it) != a.end()) || (!ina && b.find(it) != b.end()))
                        return false;
                    if (ina) {
                        if (b.find(it) == b.end()) {
                            q.push(it);
                            b.insert(it);
                        }
                    }
                    else {
                        if (a.find(it) == a.end()) {
                            q.push(it);
                            a.insert(it);
                        }
                    }
                }
            }
        }
        return true;
    }
};
