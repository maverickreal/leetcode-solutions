// { Driver Code Starts




#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution{
public:
typedef long long ll;
typedef long double ld;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
vi(string)res;
ll sz;
vi(ll)ump;
void func(string& s) {
    ll szs = s.length();
    if (szs == sz / 2) {
        string tmp = s, cpy = s;
        if (sz & 1) {
            for (ll i = 0;i < 26;++i) {
                if (ump[i]) {
                    s.pb('a' + i);
                    break;
                }
            }
        }
        reverse(tmp.begin(), tmp.end());
        s.append(tmp);
        res.pb(s);
        s = cpy;
        return;
    }
    for (ll i = 0;i < 26;++i) {
        if (!ump[i])
            continue;
        if (ump[i] == 1) {
            if (!(sz & 1))
                return;
            continue;
        }
        s.pb('a' + i);
        ump[i] -= 2;
        func(s);
        ump[i] += 2;
        s.pop_back();
    }
}
vector<string> all_plaindromes(string& s) {
    ump.resize(26, 0);
    sz = s.length();
    if (sz == 1)
        return { s };
    for (char& ch : s)
        ump[ch - 'a']++;
    s.clear();
    func(s);
    return res;
}
};



// { Driver Code Starts.
int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s;
    	cin >> s;
        Solution ob;
    	vector<string> ans  = ob.all_plaindromes(s);
    	cout<<"{ ";
    	for(auto i: ans)
    		cout << i << " ";
    	cout<<"}";
    	cout<<"\n";
    }
	return 0;
}

  // } Driver Code Ends