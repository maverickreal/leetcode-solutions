class Solution {
public:
    class cmp{
    public:
        bool operator()(const vector<int>&a, const vector<int>&b){
            return (a[2]>b[2]);
        }
    };
    int minimumTime(vector<vector<int>>&v) {
        if(v[0][1]>1 && v[1][0]>1){
            return -1;
        }
        int m=v.size(), n=v[0].size();
        priority_queue<vector<int>, vector<vector<int>>, cmp>pq;
        vector<vector<int>>vis(m, vector<int>(n)), dirs = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        pq.push({0, 0, 0});
        vis[0][0]=1;
        while(!pq.empty()){
            auto it=pq.top();
            pq.pop();
            if(it[0]==m-1 && it[1]==n-1){
                return it[2];
            }
            for(const auto&dir : dirs){
                int x=dir[0]+it[0], y=dir[1]+it[1];
                if(x>-1 && y>-1 && x<m && y<n && !vis[x][y]){
                    if(v[x][y]<=it[2]+1){
                        pq.push({x, y, it[2]+1});
                    } else{
                        bool inc = !((v[x][y]-it[2])&1);
                        pq.push({x, y, v[x][y]+inc});
                    }
                    vis[x][y]=1;
                }
            }
        }
        return -1;
    }
};