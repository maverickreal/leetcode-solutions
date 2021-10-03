class TimeMap {
public:
    unordered_map<string,vector<pair<string,int>>>ump;
    int lBound(const vector<pair<string,int>>&v, int time){
        if(v.empty() || v.front().second>time)
            return -1;
        int i=0,j=v.size()-1;
        while(i<j){
            int m=i+((j-i)>>1);
            if(v[m].second>time)
                j=m-1;
            else if(v[m].second<time){
                if(i==m){
                    if(v[j].second<=time)
                        i=j;
                    break;
                }
                i=m;
            }
            else
                break;
        }
        return (v[i+((j-i)>>1)].second<=time?i+((j-i)>>1):-1);
    }
    TimeMap(){}
    void set(string key, string value, int time) {
        ump[key].push_back({value,time});
    }
    
    string get(string key, int time) {
        int in=lBound(ump[key],time);
        if(in==-1)
            return "";
        return ump[key][in].first;
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */