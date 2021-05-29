class Solution {
    static bool cmp(const vector<int>&v1,const vector<int>&v2){
      if(v1[0]>v2[0])
        return false;
      if(v1[0]==v2[0])
        return v1[1]<v2[1];
      return true;
    }
  int dis(const vector<int>&a,const vector<int>&b){
    return pow(abs(a[0]-b[0]),2)+pow(abs(a[1]-b[1]),2);
  }
public:
    bool validSquare(const vector<int>&a,const vector<int>&b,const vector<int>&c,const vector<int>&d) {
      vector<vector<int>>tmp={a,b,c,d};
      sort(tmp.begin(),tmp.end(),cmp);
      for(int i=0;i<4;++i){
        for(int j=i+1;j<4;++j){
          if(tmp[i][0]==tmp[j][0] and tmp[i][1]==tmp[j][1])
            return false;
            }
          }
      return (dis(tmp[0],tmp[1])==dis(tmp[1],tmp[3]) and dis(tmp[3],tmp[2])==dis(tmp[1],tmp[3]) and dis(tmp[2],tmp[3])==dis(tmp[2],tmp[0]) and dis(tmp[0],tmp[3])==dis(tmp[1],tmp[2]));
    }
};