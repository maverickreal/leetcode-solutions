class Solution {
#define ln ListNode
#define tn TreeNode
    typedef long long ll;
    typedef vector<ll> vi;
#define endl '\n'
    const ll mod = 1e9;
public:
    bool digitCount(string& s) {
        vi hash(10);
        for (char& ch : s)
            ++hash[ch - '0'];
        for (ll i = 0;i < s.length();++i)
            if (hash[i] != (s[i] - '0'))return false;
        return true;
    }
};