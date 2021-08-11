class Solution {
  #define inte uint32_t
public:
    uint32_t reverseBits(uint32_t n) {
      inte pow=31,res=0;
      while(n){
        inte tmp=n&1;
        n>>=1;
        tmp<<=pow--;
        res+=tmp;
      }
      return res;
    }
};