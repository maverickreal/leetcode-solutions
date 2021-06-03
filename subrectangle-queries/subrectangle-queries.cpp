class SubrectangleQueries {
public:
    vector<vector<int>>* v, l;
    SubrectangleQueries(vector<vector<int>>& rectangle) {
        v = &rectangle;
    }

    void updateSubrectangle(int x1, int y1, int x2, int y2, int m) {
        l.push_back({ x1,y1,x2,y2,m });
    }

    int getValue(int x, int y) {
        for (int i = l.size() - 1;i > -1;--i)
            if (x >= l[i][0] && x <= l[i][2] && y >= l[i][1] && y <= l[i][3])
                return l[i].back();
        return v->at(x)[y];
    }
};