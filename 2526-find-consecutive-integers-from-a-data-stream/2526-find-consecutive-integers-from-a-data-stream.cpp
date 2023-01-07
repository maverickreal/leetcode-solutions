class DataStream {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
const vi(vi(ll))dirs={{-1, 0}, {0, -1}, {1, 0}, {0, 1}};
public:
    ll val, k, pre, ts;
    DataStream(int value, int K) {
        val=value, k=K;
        pre=-1, ts=0;
    }
    
    bool consec(int num) {
        if(num!=val){
            pre=ts;
        }
        bool ans=ts-pre>=k;
        ++ts;
        return ans;
    }
};

/**
 * Your DataStream object will be instantiated and called as such:
 * DataStream* obj = new DataStream(value, k);
 * bool param_1 = obj->consec(num);
 */