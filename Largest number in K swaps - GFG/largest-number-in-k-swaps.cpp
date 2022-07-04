// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution {
    typedef long long ll;
    typedef long double ld;
    typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define li(x) list<x>
#define pb push_back
    const ll mod = 1e9 + 7;
    const char nl = '\n';
public:
    string res;
    // void swap(string& cur, ll i, ll j) {
    //     cur[i] += cur[j];
    //     cur[j] = cur[i] - cur[j];
    //     cur[i] -= cur[j];
    // }
    void func(string& cur, ll k, ll i) {
        ll sz = cur.length();
        res = max(res, cur);
        if (i == sz || !k)
            return;
        char mx = *max_element(cur.begin() + i + 1, cur.end());
        if(mx<=cur[i])
        return func(cur, k, i+1);
        for (ll j = sz - 1;j > i;--j) {
            if (cur[j] == mx) {
                swap(cur[i], cur[j]);
                func(cur, k - 1, i + 1);
                swap(cur[i], cur[j]);
                //break;
            }
        }
    }
    string findMaximumNum(string& str, int k) {
        func(str, k, 0);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends