class Solution {
public:
    bool checkInclusion(string&s1, string&s2) {
        int sz1=s1.length(),sz2=s2.length();
        if(sz1>sz2)
            return false;
        int i=0,j=sz1-1;
        vector<int>v(26),vec(26);
        for(int k=i;k<=j;++k){
            ++vec[s2[k]-'a'];
            ++v[s1[k]-'a'];
        }
        while(++j<sz2 && v!=vec){
            --vec[s2[i++]-'a'];
            ++vec[s2[j]-'a'];
        }
        return v==vec;
    }
};