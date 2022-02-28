#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& v1, vector<int>& v2) {
        int m = v1.size(), n = v2.size();
        unordered_map<int, int>ump;
        stack<int>st;
        st.push(v2.front());
        for (int i = 1;i < n;i++) {
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
        for (int i = 0;i < m;++i)
            v1[i] = ump[v1[i]];
        return v1;
    }
    int main() {
        return 0;
    }
};