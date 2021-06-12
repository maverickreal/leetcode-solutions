class Solution {
public:
    int m, n;
    vector<vector<int>>row, col, dia, * V;
    int func(int a, int b, int x, int y) {
        int r = row[a][y] - (b ? row[a][b - 1] : 0);
        for (int i = a + 1;i <= x;++i) {
            int tmp = row[i][y] - (b ? row[i][b - 1] : 0);
            if (r != tmp)
                return -1;
        }
        int c = col[x][b] - (a ? col[a - 1][b] : 0);
        if (c != r)
            return -1;
        for (int j = b + 1;j <= y;++j) {
            int tmp = col[x][j] - (a ? col[a - 1][j] : 0);
            if (c != tmp)
                return -1;
        }
        int d = dia[x][y] - (a && b ? dia[a - 1][b - 1] : 0);
        if (d != c)
            return -1;
        int sum = 0;
        for (int r = a, c = y;r <= x && c >= b;++r, --c)
            sum += V->at(r)[c];
        return sum == d ? x - a + 1 : -1;
    }
    int largestMagicSquare(vector<vector<int>>& v) {
        V = &v;
        m = v.size(), n = v[0].size();
        int res = 1;
        row.resize(m, vector<int>(n)), col = row, dia = col;
        for (int i = 0;i < m;++i) {
            int sum = 0;
            for (int j = 0;j < n;++j) {
                sum += v[i][j];
                row[i][j] = sum;
            }
        }
        for (int i = 0;i < n;++i) {
            int sum = 0;
            for (int j = 0;j < m;++j) {
                sum += v[j][i];
                col[j][i] = sum;
            }
        }
        for (int i = 0;i < n;++i) {
            int sum = 0;
            for (int r = 0, c = i;r < m && c < n;++r, ++c) {
                sum += v[r][c];
                dia[r][c] = sum;
            }
        }
        for (int i = 1;i < m;++i) {
            int sum = 0;
            for (int r = i, c = 0;r < m && c < n;++r, ++c) {
                sum += v[r][c];
                dia[r][c] = sum;
            }
        }
        for (int i = 0;i < m;++i) {
            for (int j = 0;j < n;++j) {
                int tmp = 1;
                for (int r = i - 1, c = j - 1;r > -1 && c > -1;--r, --c)
                    tmp = max(tmp, func(r, c, i, j));
                res = max(res, tmp);
            }
        }
        return res;
    }
};