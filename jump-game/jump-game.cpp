class Solution {
public:
    bool canJump(vector<int>&v) {
        int i=v.size(),tar=i-1;
while(--i>-1){
  if(i+v[i]>=tar)
    tar=i;
}
return !tar;
    }
};