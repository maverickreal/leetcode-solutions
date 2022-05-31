typedef long long ll;
typedef long double ld;
typedef vector<ll> vi;
#define endl '\n'
#define tn TreeNode
#define ln ListNode
const ll mod = 1e9;

template<typename a, typename b, typename c>
class tri {
public:
    a x;
    b y;
    c z;
    tri(a x, b y, c z) {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    tri() {
        this->x = *(new a);
        this->y = *(new b);
        this->z = *(new c);
    }
};

class cmp {
public:
    bool operator()(const tri<ll, ll, ll>& a, const tri<ll, ll, ll>& b) {
        return a.z > b.z;
    }
};

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& v) {
        ll m = v.size(), n = v[0].size();
        priority_queue < tri<ll, ll, ll>, vector<tri<ll, ll, ll>>, cmp>pq;
        pq.push({ 0, 0, v[0][0] });
        ll res = LLONG_MAX;
        while (!pq.empty()) {
            tri t = pq.top();
            pq.pop();
            if (t.x < 0 || t.y < 0 || t.x >= m || t.y >= n || v[t.x][t.y] == -1)
                continue;
            v[t.x][t.y] = -1;
            if (t.x == m - 1 && t.y == n - 1) {
                res = t.z;
                break;
            }
            if (t.x > 0 && v[t.x - 1][t.y] != -1)
                pq.push({ t.x - 1, t.y, t.z + v[t.x - 1][t.y] });
            if (t.y > 0 && v[t.x][t.y - 1] != -1)
                pq.push({ t.x, t.y - 1, t.z + v[t.x][t.y - 1] });
            if (t.x < m - 1 && v[t.x + 1][t.y] != -1)
                pq.push({ t.x + 1, t.y, t.z + v[t.x + 1][t.y] });
            if (t.y < n - 1 && v[t.x][t.y + 1] != -1)
                pq.push({ t.x, t.y + 1, t.z + v[t.x][t.y + 1] });
        }
        return res;
    }
};