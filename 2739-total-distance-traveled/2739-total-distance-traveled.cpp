class Solution {
public:
    int distanceTraveled(int main, int extra) {
        if(main<5){
            return main*10;
        }
        main-=5;
        int ans = 50;
        int bor = min(extra, 1);
        main+=bor, extra-=bor;
        ans+=distanceTraveled(main, extra);
        return ans;
    }
};