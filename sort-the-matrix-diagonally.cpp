class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& v) {
        int m = v.size(), n = v[0].size();
        for (int i = 0;i < m;++i) {
            vector<int>tmp;
            int x = i, y = 0;
            while (x < m && y < n) {
                tmp.push_back(v[x][y]);
                ++x, ++y;
            }
            sort(tmp.begin(), tmp.end());
            x = i, y = 0;
            int k = 0;
            while (x < m && y < n) {
                v[x][y] = tmp[k++];
                ++x, ++y;
            }
        }
        for (int i = 1;i < n;++i) {
            vector<int>tmp;
            int x = 0, y = i;
            while (x < m && y < n) {
                tmp.push_back(v[x][y]);
                ++x, ++y;
            }
            sort(tmp.begin(), tmp.end());
            x = 0, y = i;
            int k = 0;
            while (x < m && y < n) {
                v[x][y] = tmp[k++];
                ++x, ++y;
            }
        }
        return v;
    }
};