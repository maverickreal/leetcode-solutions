class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int res = -1, sz = gas.size();
        for (int i = 0;i < sz;) {
            int fuel = gas[i], j = 1;
            for (;j <= sz;++j) {
                int cur = (i + j) % sz, pre = cur ? cur - 1 : sz - 1;
                fuel -= cost[pre];
                if (fuel < 0)
                    break;
                fuel += gas[cur];
            }
            if (j == sz + 1) {
                res = i;
                break;
            }
            i +=j;
        }
        return res;
    }
};
