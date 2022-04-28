class Solution {
public:    
    // [1,2,3,4,1,2,3,4,1,2,3,4]
    
    void func(vector<int>& v) {
    int n = v.size();
    stack<int>st;
    vector<int>arr(n);
    st.push(0);
    for (int i = 1;i < n;++i) {
        while (!st.empty() && v[st.top()] < v[i]) {
            arr[st.top()] = i;
            st.pop();
        }
        st.push(i);
    }
    while (!st.empty()) {
        arr[st.top()] = n;
        st.pop();
    }
    v = arr;
}
    
    vector<int> maxSlidingWindow(vector<int>&v, int k) {
        int n = v.size();
        vector<int>res, arr = v;
        func(arr);
        int j=0;
        for (int i = 0;i <= n - k;++i) {
            j=max(j, i);
            while (arr[j] < i + k)
                j = arr[j];
            res.push_back(v[j]);
        }
        return res;
    }
};