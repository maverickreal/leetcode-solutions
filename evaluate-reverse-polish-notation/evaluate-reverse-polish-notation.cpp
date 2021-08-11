class Solution {
public:
    int evalRPN(vector<string>& v) {
        for(int i=0;i<v.size();++i){
  bool fl=false;
    if(v[i]=="+"){
      v[i-2]=to_string(stoi(v[i-2])+stoi(v[i-1]));
      fl=true;
    }
    else if(v[i]=="-"){
      v[i-2]=to_string(stoi(v[i-2])-stoi(v[i-1]));
      fl=true;
    }
    else if(v[i]=="*"){
      v[i-2]=to_string(stoi(v[i-2])*stoi(v[i-1]));
      fl=true;
    }
    else if(v[i]=="/"){
      v[i-2]=to_string(stoi(v[i-2])/stoi(v[i-1]));
      fl=true;
    }
    if(fl){
      v.erase(v.begin()+i-1,v.begin()+i+1);
      i-=2;
    }
  }
return stoi(v[0]);
    }
};