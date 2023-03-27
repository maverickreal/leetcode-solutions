class Solution {
public:
    int sz, n, ans;
    vector<int>par, size;

    int getId(int i, int j, int dir){
        return 4*(i*sz + j) + dir;
    }

    int find(int nd){
        if(par[nd]==nd){
            return nd;
        }
        return par[nd]=find(par[nd]);
    }

    void merge(int x, int y){
        x=find(x), y=find(y);
        if(x==y){
            return;
        }
        //--ans;
        if(size[y]>size[x]){
            x+=y, y=x-y, x-=y;
        }
        size[x]+=size[y];
        par[y]=x;
    }

    int regionsBySlashes(const vector<string>&v) {
        sz=v.size(), n=sz*sz*4, ans=0;
        par.resize(n), size.assign(n, 1);
        iota(begin(par), end(par), 0);
        for(int i=0; i<sz; ++i){
            for(int j=0; j<sz; ++j){
                if(v[i][j]=='/'){
                    merge(getId(i, j, 0), getId(i, j, 3));
                    merge(getId(i, j, 1), getId(i, j, 2));
                }
                else if(v[i][j]=='\\'){
                    merge(getId(i, j, 0), getId(i, j, 1));
                    merge(getId(i, j, 3), getId(i, j, 2));
                }
                else{
                    merge(getId(i, j, 0), getId(i, j, 3));
                    merge(getId(i, j, 0), getId(i, j, 1));
                    merge(getId(i, j, 1), getId(i, j, 2));
                    merge(getId(i, j, 3), getId(i, j, 2));
                }
                if(i){
                    merge(getId(i-1, j, 2), getId(i, j, 0));
                }
                if(j){
                    merge(getId(i, j, 3), getId(i, j-1, 1));
                }
            }
        }
        for(int i=0; i<n; ++i){
            ans+=par[i]==i;
        }
        return ans;
    }
};