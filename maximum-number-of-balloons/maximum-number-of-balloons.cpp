class Solution {
public:
    int maxNumberOfBalloons(string&s) {
        vector<int>v(26);
        for(char&ch:s)
            ++v[ch-'a'];
        v['l'-'a']>>=1;
        v['o'-'a']>>=1;
        return min(v['b'-'a'],min(v[0],min(v['l'-'a'],min(v['o'-'a'],v['n'-'a']))));
    }
};