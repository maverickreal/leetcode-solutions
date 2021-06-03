class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& co, vector<vector<int>>& q) {
        int szc = co.size(), szq = q.size();
        vector<int>res(szq);
        for (int i = 0;i < szq;++i) {
            for (const auto& it : co){
                int X = pow(abs(it[0] - q[i][0]), 2), Y = pow(abs(it[1] - q[i][1]), 2);
            if (pow(q[i][2], 2) >= X + Y)
                ++res[i];
            }
        }
        return res;
    }
};