class MinStack {
    list<pair<int, int>> l;
public:
    MinStack() {

    }

    void push(int val) {
        l.push_back({ val, min(val, l.empty() ? val : l.back().second) });
    }

    void pop() {
        l.pop_back();
    }

    int top() {
        return l.back().first;
    }

    int getMin() {
        return l.back().second;
    }
};
