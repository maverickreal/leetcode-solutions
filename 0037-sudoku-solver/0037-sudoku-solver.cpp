class Solution {
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';

bool solveSudoku(vector<vector<char>>&v, ll i=0, ll j=0) {
    i+=j/9, j%=9;
    if(i==9){
        //cout<<"here"<<nl;
        return 1;
    }
    if(v[i][j]!='.'){
        return solveSudoku(v, i, j+1);
    }
    ll bm=0;
    //cout<<i<<' '<<j<<nl;
    for(ll k=0;k<9;++k){
        if(v[i][k]!='.'){
            bm|=1LL<<(v[i][k]-'0');
        }
        if(v[k][j]!='.'){
            bm|=1LL<<(v[k][j]-'0');
        }
        ll r=((i/3)*3)+(k/3), c=((j/3)*3)+(k%3);
        //cout<<r<<' '<<c<<nl;
        if(v[r][c]!='.'){
            bm|=1LL<<(v[r][c]-'0');
        }
    }
    //cout<<nl;
    // cout<<i<<' '<<j<<nl;
    // for(ll k=1;k<=9;++k){
    //     cout<<((bm>>k)&1)<<' ';
    // }
    // cout<<nl;
    for(ll k=1;k<=9;++k){
        if(!((bm>>k)&1)){
            // if(!i && j==2){
            //     cout<<k<<' ';
            // }
            v[i][j]='0'+k;
            if(solveSudoku(v, i, j+1)){
                return 1;
            }
        }
    }
    v[i][j]='.';
    return 0;
}
};