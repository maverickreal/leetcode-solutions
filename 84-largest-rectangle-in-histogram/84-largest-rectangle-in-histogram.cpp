class Solution {
public:
    void nextSmallerElementRight(vector<int>& v) {
    int n = v.size();
    vector<int> ans(n);
    stack<int>st;
    st.push(0);
    for (int i = 1;i < n;i++) {
        while (!st.empty() && v[st.top()] > v[i]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        ans[st.top()] = n;
        st.pop();
    }
    v = ans;
}
void nextSmallerElementLeft(vector<int>& v) {
    stack<int>st;
    int n = v.size();
    vector<int>ans(n);
    st.push(n - 1);
    for (int i = n - 2;i > -1;--i) {
        while (!st.empty() && v[st.top()] > v[i]) {
            ans[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        ans[st.top()] = -1;
        st.pop();
    }
    v = ans;
}
    int largestRectangleArea(vector<int>&v) {
        int n=v.size();
        vector<int>r = v, l = v;
        nextSmallerElementLeft(l);
        nextSmallerElementRight(r);
        int mx = 0;
        for (int i = 0;i < n;++i) {
            int lg = l[i], rg = r[i];
            mx = max(mx, (rg - lg - 1) * v[i]);
        }
        return mx;
    }
};