class Solution {
public:
    static  bool cmp(const string& a, const string& b) {
        return a.length() > b.length();
    }
    bool func(const string& a, const string& b) {
        int i = 0, j = 0;
        for (;i < a.length() && j < b.length();++i)
            if (a[i] == b[j])
                ++j;
        bool fl = (j == b.length());
        //cout << "\n\n\n" << a << "    " << b << "    " << //(fl ? "true" : "false") << '\n';
        return fl;
    }
    int findLUSlength(vector<string>& v) {
        sort(v.begin(), v.end(), cmp);
        // for(auto s:v)
        //     cout<<s<<"  ";
        // cout<<'\n';
        //unordered_set<string>ust;
        int sz = v.size();
        for (int i = 0;i < sz;++i) {
            /* if (ust.find(v[i]) != ust.end())
                continue;*/
            //cout<<v[i]<<"   "; 
            int j = 0;
            for (;j < i;++j)
                if (func(v[j], v[i]))
                    break;
            if (j < i) {
                //ust.insert(v[i]);
                //cout << "1\n";
                continue;
            }
            j = i + 1;
            for (;j < sz;++j)
                if (func(v[j], v[i]))
                    break;
            if (j == sz)
                return v[i].length();
            // ust.insert(v[i]);
            //cout << "2\n";
        }
        return -1;
    }
};