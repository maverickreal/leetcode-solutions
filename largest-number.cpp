class Solution {
public:
  static bool cmp(const int&i,const int&j){
    string x=to_string(i),y=to_string(j);
    return x+y>y+x;
  }
    string largestNumber(vector<int>&v) {
      sort(v.begin(),v.end(),cmp);
      if(!v[0])
        return "0";
      string res="";
      for(const int&i:v)
        res.append(to_string(i));
      return res;
    }
};