class MovingAverage {
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    list<ld>l;
    ld sum;
    ll n;
    MovingAverage(int size) {
        n=size, sum=0;
    }
    
    double next(int val) {
        l.pb(val);
        sum+=val;
        while(l.size()>n){
            sum-=l.front();
            l.pop_front();
        }
        return sum/ld(l.size());
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage* obj = new MovingAverage(size);
 * double param_1 = obj->next(val);
 */