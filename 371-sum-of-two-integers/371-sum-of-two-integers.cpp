class Solution {
    typedef long long ll;
public:
    int dif(int a, int b) {
        bool bor = false;
        ll dif = 0, ptr = 0;
        while (a) {
            if (bor) {
                if (a & 1) {
                    --a;
                    bor = false;
                }
                else {
                    ++a;
                }
            }
            if (b & 1 && !(a & 1)) {
                ++a;
                bor = true;
                --b;
            }
            if ((a & 1) - (b & 1)) {
                dif |= 1 << ptr;
            }
            ++ptr;
            a >>= 1;
            b >>= 1;
        }
        return dif;
    }
    int sum(int a, int b) {
        ll sum = 0, ptr = 0;
        bool car = false;
        while (a || b) {
            if (car) {
                if (a & 1 && b & 1) {
                    sum |= 1 << ptr;
                }
                else if (!(a & 1 || b & 1)) {
                    sum |= 1 << ptr;
                    car = false;
                }
            }
            else {
                if (a & 1 && b & 1) {
                    car = true;
                }
                else if (a & 1 || b & 1) {
                    sum |= 1 << ptr;
                }
            }
            a >>= 1;
            b >>= 1;
            ptr++;
        }
        if (car) {
            sum |= 1 << ptr;
        }
        return sum;
    }
    int getSum(int a, int b) {
        if ((a<0 && b>-1) || (a > -1 && b < 0)) {
            ll x = max(a, b), y = min(a, b);
            ll ans = dif(max(x, abs(y)), min(x, abs(y)));
            if (abs(y) > x) {
                ans *= -1;
            }
            // cout<<x<<' '<<y<<' '<<ans<<nl;
            return ans;
        }
        return sum(abs(a), abs(b)) * (a < 0 && b < 0 ? -1 : 1);
    }
};