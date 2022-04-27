class Solution {
public:
    typedef long long ll;
#define endl '\n'
const ll mod = 1e9 + 7;

vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
    unordered_map<ll, ll>ump;
    stack<ll>st;
    for (ll i = 0;i < v2.size();++i) {
        while (!st.empty() && st.top() < v2[i]) {
            ump[st.top()] = v2[i];
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
};
