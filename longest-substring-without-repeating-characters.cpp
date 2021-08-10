class Solution {
public:
    int lengthOfLongestSubstring(string&s) {
        int res=0,sz=s.length(),i=-1,j=0;
        if(sz<2)
            return sz;
vector<int>ump(128,-1);
while(++i<sz){
    int x=ump[s[i]];
if(x!=-1){
for(int k=j;k<x;++k)
    ump[s[k]]=-1;
j=x+1;
}
else
    res=max(res,i-j+1);
ump[s[i]]=i;
}
return res;
    }
};