class Solution {
public:
    void rotate(vector<vector<int>>&v) {
        int sz=v.size();
for(int i=0;i<sz;++i){
  for(int j=i;j<sz;++j)
    swap(v[i][j],v[j][i]);
}
for(int i=0;i<sz;++i)
  reverse(v[i].begin(),v[i].end());
}
};