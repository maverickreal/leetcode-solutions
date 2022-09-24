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
        return (ch=='+' || ch=='-' || ch=='*' || ch=='/');
    }

    void dm(string&s){
        ll sz=s.size();
        string ans;
        for(ll i=0;i<sz;++i){
            char cur=s[i];
            if(cur==' '){
                continue;
            }
            if(cur=='/' || cur=='*'){
                string left;
                while(!ans.empty() && isNum(ans.back())){
                    left.pb(ans.back());
                    ans.pop_back();
                }
                reverse(left.begin(), left.end());
                ll in=i+1;
                string right;
                for(;in<sz;++in){
                    if(s[in]== ' '){
                        continue;
                    }
                    if(isNum(s[in])){
                        right.pb(s[in]);
                    }
                    else{
                        break;
                    }
                }
                i=in-1;
                //cout<<left<<' '<<right<<nl;
                ans.append(to_string(cur=='/'?(stoll(left)/stoll(right)):(stoll(left)*stoll(right))));
            }
            else{
                ans.pb(cur);
            }
        }
        s=ans;
    }
    int calculate(string&s) {
        dm(s);
        ll ans=0;
        while(!s.empty()){
            if(isOp(s.back())){
                s.pop_back();
                continue;
            }
            string num;
            while(!s.empty() && isNum(s.back())){
                num.pb(s.back());
                s.pop_back();
            }
            reverse(num.begin(), num.end());
            ll it=stoll(num);
            if(!s.empty() && s.back()=='-'){
                it=-it;
            }
            ans+=it;
        }
        return ans;
    }
};