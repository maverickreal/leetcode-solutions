class Solution {
public:
typedef long long ll;
#define endl '\n'
const ll mod = 1e9 + 7;

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

ll res = LLONG_MIN;

void travel(const vector<vector<int>>& v) {
    queue<vector<ll>>q;
    q.push({ 0,0,1,0, LLONG_MAX });
    vector<vector<bool>>vis(v.size(), vector<bool>(v[0].size(), false));
    while (!q.empty()) {
        ll i = q.front()[0], j = q.front()[1], time = q.front()[2], tmnsf = q.front()[3], mnsf = q.front()[4];
        q.pop();
        if (i < 0 || i >= v.size() || j < 0 || j >= v[0].size() || v[i][j]>0 || (v[i][j] && abs(v[i][j]) < time) || vis[i][j])
            continue;
        vis[i][j] = true;
        ll cur = abs(v[i][j]), ans = cur - time - (i != v.size() - 1 || j != v[0].size() - 1);
        bool pre = true;
        if (mnsf == LLONG_MAX || ans < mnsf - tmnsf - 1) {
            mnsf = cur;
            tmnsf = time;
            pre = false;
            //cout<<"mnsf : "<<mnsf<<' '<<tmnsf<<endl;
        }
        if (i == v.size() - 1 && j == v[0].size() - 1) {
            //cout << "End : " << time << ' ' << tmnsf << ' ' << mnsf << ' ' << res << endl;
            if (mnsf)
                res = max(res, mnsf - tmnsf - (pre ? 1 : 0));
            else
                res = mod - 7;
            vis[i][j]=false;
            continue;
        }
        if (abs(v[i][j]) == time)
            continue;
        q.push({ i, j + 1, time + 1, tmnsf, mnsf });
        q.push({ i + 1, j, time + 1, tmnsf, mnsf });
        q.push({ i - 1, j, time + 1, tmnsf, mnsf });
        q.push({ i, j - 1, time + 1, tmnsf, mnsf });
    }
}

int maximumMinutes(vector<vector<int>>& v) {
    // for (const auto& it : v) {
    //     for (const int& ti : it)
    //         cout << ti << ' ';
    //     cout << endl;
    // }
    queue<tri<ll, ll, ll>> q;
    const ll m = v.size(), n = v[0].size();
    for (ll i = 0;i < m;i++) {
        for (ll j = 0;j < n;j++) {
            if (v[i][j] == 1) {
                v[i][j] = -1;
                q.push({ i, j + 1 ,-2 });
                q.push({ i + 1, j ,-2 });
                q.push({ i, j - 1,-2 });
                q.push({ i - 1, j ,-2 });
            }
        }
    }
    while (!q.empty()) {
        ll i = q.front().x, j = q.front().y, k = q.front().z;
        q.pop();
        if (i < 0 || i >= m || j < 0 || j >= n || v[i][j]>0 || (v[i][j] && abs(v[i][j]) <= abs(k)))
            continue;
        v[i][j] = k;
        --k;
        q.push({ i, j + 1, k });
        q.push({ i + 1, j, k });
        q.push({ i, j - 1, k });
        q.push({ i - 1, j, k });
    }
    travel(v);
    //cout << endl << "res : " << res << endl;
    if (res == LLONG_MIN)
        res = -1;
    // for (const auto& it : v) {
    //     for (const int& ti : it)
    //         cout << ti << ' ';
    //     cout << endl;
    // }
    return res;
}
};