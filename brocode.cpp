#include "iostream"
#include "vector"
#include "list"
#include "limits.h"
#include "stack"
#include "unordered_map"

using namespace std;

typedef long long ll;
#define endl '\n'
const ll mod = 1e9 + 7;

vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
    unordered_map<ll, ll>ump;
    stack<ll>st;
    for (ll i = 0;i < v2.size();++i) {
        while (!st.empty() && st.top() < v2[i]) {
            ump[st.top()] = i;
            st.pop();
        }
        st.push(v2[i]);
    }
    while (!st.empty()) {
        ump[st.top()] = -1;
        st.pop();
    }
    for (int& i : v1)
        i = ump[i];
    return v1;
}

int main() {
    string s;
    getline(cin, s);
    stack<char>st;
    for (const char& ch : s) {
        if (ch == ')') {
            if (st.top() == '(') {
                cout << "true" << endl;
                return 0;
            }
            while (st.top() != '(')
                st.pop();
            st.pop();
        }
        else
            st.push(ch);
    }
    cout << "false" << endl;
    return 0;
}