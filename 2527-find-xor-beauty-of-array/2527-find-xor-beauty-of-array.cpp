class Solution {
typedef long long ll;
#define vi(x) vector<x>
public:
    void getCnt(const vi(int)&v, vi(ll)&cnt){ // prefix
            vi(ll)osf(32); // osf[i]=count of numbers with ith bit set (Ones So Far)
            for(ll i=0;i<v.size();++i){
                for(ll j=0;j<32;++j){
                    if((v[i]>>j)&1){
                        cnt[j]+=2*i+1; // *2 for duplicacy, +1 for the pair (i,i)
                    }
                    else{
                        cnt[j]+=2*osf[j]; // just couple with existing ones, no other choice
                    }
                    osf[j]+=(v[i]>>j)&1;
                }
            }
    }
    // a triplet ((i | j) & k) is effective if it evaluates to 1
    int xorBeauty(vector<int>&v) {
        ll ans=0;
        vi(ll)cnt(32); // cnt[i]=count of numbers having ith bit set
        getCnt(v, cnt);
        for(ll i=0;i<32;++i){ // preparing the ith bit of the answer
            bool odd=0; // for ith bit to be set, count of effective triplets should be odd, due to XOR property
            for(ll it:v){ // think of 'it' as the 'k' in the expression '(i | j) & k'
                if(((it>>i)&1) && (cnt[i]&1)){
                    odd=!odd;
                }
                // ((it>>i)&1) -> if current bit is zero, all triplets formed will be ineffective, as the bit will be zero, regardless of the remaining part of the expression (i | j)
                // (cnt[i]&1) -> count of pairs with ith bit set must be odd for ith bit of the overall XOR to be set
            }
            if(odd){
                ans|=1LL<<i;
            }
        }
        return ans;
    }
};