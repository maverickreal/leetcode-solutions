class Solution {
public:
    void reverseString(vector<char>& v) {
        if(v.size()<2)
            return;
        reverse (v.begin(),v.end());
    }
};