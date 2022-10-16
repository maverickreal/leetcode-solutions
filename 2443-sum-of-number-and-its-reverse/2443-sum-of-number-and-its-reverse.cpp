class Solution {
typedef long long ll;
public:
    ll reverse(ll num) {
	    ll result = 0;
	    while(num > 0){
            result = result * 10 + (num % 10);
            num /= 10;
        }
	    return result;
    }
    bool sumOfNumberAndReverse(int n) {   
        for(ll i=0;i<=n;++i){
            if(i+reverse(i)==n){
                return 1;
            }
        }
        return 0;
    }
};