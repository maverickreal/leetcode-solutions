class Solution {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    bool invalid(const int& bm) {
        return (bm > 191 || bm < 128);
    }
    int func(const int& bm) {
        if ((bm & 128) == 0) {
            return 1;
        }
        if ((bm & 64) && !(bm & 32)) {
            return 2;
        }
        if ((bm & 64) && (bm & 32) && !(bm & 16)) {
            return 3;
        }
        if ((bm & 64) && (bm & 32) && (bm & 16) && !(bm & 8)) {
            return 4;
        }
        return 0;
    }
    bool validUtf8(vector<int>& v) {
        int sz = v.size();
        for (int i = 0;i < sz;++i) {
            const int& bm = v[i];
            int type = func(bm);
            //cout<<bm<<' '<<type<<nl;
            if (type == 0) {
                return false;
            }
            if (type == 1) {
                continue;
            }
            if (type == 2) {
                if (i + 1 == sz || invalid(v[i + 1])) {
                    return false;
                }
                ++i;
                continue;
            }
            if (type == 3) {
                if (i + 2 >= sz || invalid(v[i + 1]) || invalid(v[i + 2])) {
                    return false;
                }
                i += 2;
                continue;
            }
            if (i + 3 >= sz || invalid(v[i + 1]) || invalid(v[i + 2]) || invalid(v[i + 3])) {
                return false;
            }
            i += 3;
        }
        return true;
    }
};