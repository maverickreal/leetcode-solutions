class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    bool isNum(char ch){
        return (ch>='0' && ch<='9');
    }
    bool isOp(char ch){
        return (ch=='+' || ch=='-');
    }
    int calculate(string&s) {
        ll sz=s.size()+1;
        list<string>l={"("};
        s.pb(')');
        for(ll i=0;i<sz;++i){
            char cur=s[i];
            if(cur==' '){
                continue;
            }
            if(cur=='(' || isOp(cur)){
                string tmp;
                tmp.pb(cur);
                l.pb(tmp);
            }
            else if(isNum(cur)){
                if(!l.empty() && isNum(l.back().back())){
                    l.back().pb(cur);
                }
                else{
                    string tmp;
                    tmp.pb(cur);
                    l.pb(tmp);
                }
            }
            else{
                ll res=0;
                while(l.back()!="("){
                    string it=l.back();
                    l.pop_back();
                    if(it=="+" || it=="-"){
                        continue;
                    }
                    ll num=stoll(it);
                    if(!l.empty() && l.back()=="-"){
                        num*=-1;
                    }
                    res+=num;
                }
                l.back()=to_string(res);
            }
        }
        return stoll(l.back());
    }
};