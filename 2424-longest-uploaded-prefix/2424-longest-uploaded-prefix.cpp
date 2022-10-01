class LUPrefix {
    int mx;
    vector<bool>ump;
    public:
    LUPrefix(int n) {
        ump.assign(n+2, false);
        ump[0]=true;
        mx=1;
    }

    void upload(int v) {
        ump[v]=true;
        while(ump[mx]){
            ++mx;
        }
    }

    int longest() {
        return mx-1;
    }
};