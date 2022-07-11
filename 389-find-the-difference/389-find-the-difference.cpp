class Solution {
public:
    char findTheDifference(string s, string t) {
       int xo=0;
        for(char ch:s)
            xo^=(ch-'a');
        for(char ch:t)
            xo^=(ch-'a');
        return ('a'+xo);
    }
};