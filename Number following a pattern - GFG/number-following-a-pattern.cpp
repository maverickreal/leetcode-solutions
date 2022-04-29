// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution{   
public:
typedef long long ll;
#define endl '\n'
const ll mod = 1e9 + 7;

string printMinNumberForPattern(const string& s) {
    const ll sz = s.length();
    ll num = 1;
    stack<ll>st;
    string res;
    for (ll i = 0;i < sz;++i) {
        const char& ch = s[i];
        st.push(num++);
        if (ch == 'I') {
            while (!st.empty()) {
                res.push_back('0'+st.top());
                st.pop();
            }
        }
    }
    st.push(num);
    if(!st.empty()){
        while (!st.empty()) {
            res.push_back('0'+st.top());
            st.pop();
        }
    }
    return res;
}
};


// { Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string S;
        cin >> S;
        Solution ob;
        cout << ob.printMinNumberForPattern(S) << endl;
    }
    return 0; 
} 
  // } Driver Code Ends