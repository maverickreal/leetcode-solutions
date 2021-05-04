class Solution {
  #define inte uint32_t
public:
    int hammingWeight(uint32_t n) {
        int res=0;
        while(n){
          res+=(n&1);
          n>>=1;
        }
        return res;
    }
};