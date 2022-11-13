class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(ll)arr;
    int minSwaps(){
        ll n=arr.size(), ans = 0;
        vi(ll)temp(begin(arr), end(arr));
        unordered_map<ll,ll>h;
        sort(temp.begin(), temp.end());
        for (ll i = 0; i < n; i++){
            h[arr[i]] = i;
        }
        for (ll i = 0; i < n; i++){
            if (arr[i] == temp[i]){
                continue;
            }
                ans++;
                ll init = arr[i];
                arr[i]+=arr[h[temp[i]]];
                arr[h[temp[i]]]=arr[i]-arr[h[temp[i]]];
                arr[i]-=arr[h[temp[i]]];
                h[init] = h[temp[i]], h[temp[i]] = i;
        }
        arr.clear();
        return ans;
    }
    int minimumOperations(TreeNode* root) {
        deque<TreeNode*>dq={root};
        ll ans=0;
        while(!dq.empty()){
            ll sz=dq.size();
            for(ll i=0;i<sz;++i){
                auto nd=dq.front();
                dq.pop_front();
                arr.pb(nd->val);
                if(nd->left){
                    dq.pb(nd->left);
                }
                if(nd->right){
                    dq.pb(nd->right);
                }
            }
            ans+=minSwaps();
        }
        return ans;
    }
};