class Solution {
public:
    vector<int> threeEqualParts(vector<int>& v) {
        int sz = v.size(), sum = accumulate(v.begin(), v.end(), 0);
        if (sum % 3)
            return { -1,-1 };
        if (!sum)
            return { 0,2 };
        //cout << "1\n\n\n";
        sum /= 3;
        int tot = 0;
        int sx = -1, sy = sx, mx = sx, my = sx, ex = sx, ey = sx;
        for (int i = 0;i < sz;++i) {
            if (v[i]) {
                ++tot;
                if (tot == 1)
                    sx = i;
                if (tot == sum)
                    sy = i;
                if (tot == sum + 1)
                    mx = i;
                if (tot == (sum << 1))
                    my = i;
                if (tot == (sum << 1) + 1)
                    ex = i;
                if (tot == (sum * 3))
                    ey = i;
            }
        }
        vector<int>a(v.begin() + sx, v.begin() + sy + 1), b(v.begin() + mx, v.begin() + my + 1), c(v.begin() + ex, v.begin() + ey + 1);
        if (a != b || b != c)
            return { -1,-1 };
        if (mx - sy < sz - ey || ex - my < sz - ey)
            return { -1, -1 };
        return { sy+sz-1-ey,my + sz-ey };
    }
};