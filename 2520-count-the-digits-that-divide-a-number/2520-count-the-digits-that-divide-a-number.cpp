class Solution {
public:
int countDigits(int n) {
    int m=n, ans=0;
    while(m>0){
        int x=m%10;
        m/=10;
        ans+=(n%x)==0;
    }
    return ans;
}
};