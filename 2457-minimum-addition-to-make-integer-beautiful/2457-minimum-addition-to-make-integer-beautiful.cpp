class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    long long makeIntegerBeautiful(const ll&n, int tar) {   
        ll sum=0, m=n;
        while(m){
            sum+=m%10, m/=10;
        }
        if(sum<=tar){
            return 0;
        }
        m=n;
        ll car=0;
        string ans;
        while(sum>tar || car){
            ll last=(m%10)+car;
            car=last/10, last%=10;
            sum+=last-(m%10);
            if(!last){
                m/=10;
                ans.pb('0');
                continue;
            }
            if(sum>tar){
                ans.pb('0'+10-last);
                sum-=last, m/=10, ++car;
            }
        }
        reverse(begin(ans), end(ans));
        //cout<<ans<<nl;
        return stoll(ans);
    }
};