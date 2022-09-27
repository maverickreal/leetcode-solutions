class HitCounter {
public:
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    list<pi>l;
    ll cnt=0;
    HitCounter() {
        
    }
    void hit(int ts) {
      while(!l.empty() && l.front().first<=ts-300){
        cnt-=l.front().second;
        l.pop_front();
      }
      ++cnt;
      if(!l.empty() && l.back().first==ts){
        ++l.back().second;
      }
      else{
        l.pb({ts, 1});
      }
    }
    
    int getHits(int ts) {
        while(!l.empty() && l.front().first<=ts-300){
            cnt-=l.front().second;
            l.pop_front();
        }
        return cnt;
    }
};