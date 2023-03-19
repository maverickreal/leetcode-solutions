class Solution {
private:
    const vector<pair<int, int>>dirs={{-2, -1}, {-2, 1}, {2, -1}, {2, 1}, {-1, -2}, {1, -2}, {-1, 2}, {1, 2}};    
public:
    bool checkValidGrid(vector<vector<int>>&v) {
        int n=v.size();
        if(v[0][0]!=0){
            return false;
        }
        int vis=0;
        for(int i=0, j=0;vis<=n*n;){
            ++vis;
            int I=-1, J=-1;
            for(auto [x, y]:dirs){
                x+=i, y+=j;
                if(!(x<0 || x>=n || y<0 || y>=n || v[x][y]!=v[i][j]+1)){
                    I=x, J=y;
                    break;
                }
            }
            v[i][j]=-1;
            if(I==-1 && J==-1){
                break;
            }
            i=I, j=J;
        }
        return (vis==n*n);
    }
};