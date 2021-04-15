class Solution {
public:
  vector<vector<int>>*v;
  int m,n;
  bool func(int&tar,int b,int e){
    if(b>e)
      return false;
    int mid=(b+e)>>1;
    int i=mid/n,j=mid%n;
    if((*v)[i][j]==tar)
      return true;
    if((*v)[i][j]<tar)
      return func(tar,mid+1,e);
    return func(tar,b,mid-1);
  }
    bool searchMatrix(vector<vector<int>>&mat, int tar) {
      v=&mat;
      m=mat.size();
      if(!m)
        return false;
      n=mat[0].size();
      return func(tar,0,(m*n)-1);
    }
};