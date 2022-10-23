class Solution {
typedef int ll;
public:
    ll getTime(const string&s){ // get timesin mins
        ll ans=stoll(s.substr(3)); // mins
        ans+=60*stoll(s.substr(0, 2)); // hours into mins
        return ans;
    }
    bool haveConflict(vector<string>&a, vector<string>&b) {
        ll sa=getTime(a[0]), ea=getTime(a[1]), sb=getTime(b[0]), eb=getTime(b[1]); // start of a and b, end of a and b
        return ((sb>=sa && sb<=ea) || (sa>=sb && sa<=eb)); // do they intersect in any direction?
    }
};