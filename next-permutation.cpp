class Solution {
public:
    void nextPermutation(vector<int>& v) {
      int i=v.size()-1;
      while(i and v[i]<=v[i-1])
        --i;
      if(i){
        --i;
        int j=v.size()-1;
        while(j and v[j]<=v[i])
          --j;
        v[j]+=v[i];
        v[i]=v[j]-v[i];
        v[j]-=v[i];
        ++i;
        j=v.size()-1;
        while(i<j){
          v[j]+=v[i];
          v[i]=v[j]-v[i];
          v[j]-=v[i];
          ++i;
          --j;
    }
  }
       else
    sort(v.begin(),v.end()); 
}
};
//[4,2,0,2,3,2,0]