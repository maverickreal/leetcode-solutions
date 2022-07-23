class NumberContainers {
    typedef long long ll;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
    unordered_map < ll, set<ll>>pos;
    unordered_map<ll, ll>ump;
public:
    NumberContainers() {}

    void change(int ind, int num) {
        if (ump[ind] == num) return;
        ll it = ump[ind];
        ump[ind] = num;
        pos[num].insert(ind);
        pos[it].erase(ind);
    }

    int find(int num) {
        return (pos[num].empty() ? -1 : *pos[num].begin());
    }
};