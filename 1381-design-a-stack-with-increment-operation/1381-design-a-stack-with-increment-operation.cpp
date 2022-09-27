class CustomStack {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    ll n;
    list<ll>l;
    vi(ll)inc;
    CustomStack(int sz) {
        n=sz;
    }
    
    void push(int x) {
        if(l.size()<n){
            l.pb(x);
            inc.pb(0);
        }
    }
    
    int pop() {
        ll sz=l.size(), ret=-1;
        if(!sz){
            return ret;
        }
        ret=l.back()+inc.back();
        if(sz>1){
            inc[sz-2]+=inc.back();
        }
        l.pop_back(), inc.pop_back();
        return ret;
    }
    
    void increment(int k, int val) {
        ll in=min(k, int(l.size()))-1;
        if(in>-1){
            inc[in]+=val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */