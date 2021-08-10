class Solution {
public:
  #define nd Node
    int maxDepth(nd*rt,int len=0) {
        if(rt==NULL)
          return len;
        ++len;
        if(rt->children.empty())
          return len;
        int j=0;
        for(nd* i:rt->children)
          j=max(j,maxDepth(i,len));
        return j;
    }
};