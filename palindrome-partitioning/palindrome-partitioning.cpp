class Solution {
    string s;
    vector<vector<string>>res;
    vector<vector<bool>>palin;
    int sz;
    void dfs(int i = 0, vector<string>v = {}) {
        if (i == sz) {
            res.push_back(v);
            return;
        }
        for (int j = i;j < sz;++j) {
            if (palin[i][j]) {
                v.push_back(s.substr(i, j - i + 1));
                dfs(j + 1, v);
                v.pop_back();
            }
        }
    }
public:
    vector<vector<string>> partition(string& S) {
        s = move(S);
        sz = s.length();
        palin.resize(sz, vector<bool>(sz));
        for (int i = 0;i < sz;++i) {
            for (int r = 0, c = i;r < sz && c < sz;++r, ++c) {
                if (r == c) {
                    palin[r][c] = true;
                    continue;
                }
                palin[r][c] = s[r] == s[c] && (c == r + 1 || palin[r + 1][c - 1]);
            }
        }
        dfs();
        return res;
    }
};