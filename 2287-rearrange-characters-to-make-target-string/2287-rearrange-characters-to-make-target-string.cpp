class Solution{
    typedef int ll;
    typedef vector<ll> vi;
    const ll mod = 1e9;
#define ln ListNode
#define tn TreeNode
#define endl '\n'
public:
    int rearrangeCharacters(string& s, string& tar) {
        vi umpt(26,0);
        for (char& ch : tar)umpt[ch - 'a']++;
        vi umps(26,0);
        for (char& ch : s)umps[ch - 'a']++;
        ll res = INT_MAX;
        for (ll i = 0;i < 26;++i) {
            if (!umpt[i])continue;
            if (umps[i] < umpt[i])return 0;
            ll cnt = umps[i] / umpt[i];
            //cout<<cnt<<' ';
            res = min(res, cnt);
        }
        return res;
    }
};