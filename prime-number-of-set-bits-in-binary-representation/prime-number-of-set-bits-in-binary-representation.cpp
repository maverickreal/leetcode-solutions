class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        unordered_set<int>ust={2,3,5,7,11,13,17,19,23,29,31};
        int res=0;
        for(int i=left;i<=right;++i){
            int cnt=0,j=i;
            while(j){
                cnt+=j&1;
                j>>=1;
            }
            res+=ust.find(cnt)!=ust.end();
        }
        return res;
    }
};