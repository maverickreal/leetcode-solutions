class Solution {
public:
    int characterReplacement(string&s, int k) {
        int l=0,mc=0,ml=0,sz=s.length();
        vector<int>v(26);
        for(int i=0;i<sz;++i){
        	++v[s[i]-'A'];
        	mc=max(mc,v[s[i]-'A']);
        	while(l<i && i-l+1-mc>k)
        		--v[s[l++]-'A'];
        	ml=max(ml,i-l+1);
        }
        return ml;
    }
};