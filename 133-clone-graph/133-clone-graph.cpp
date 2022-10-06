class Solution {
typedef long long ll;
typedef pair<ll, ll> pi;
#define vi(x) vector<x>
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';
public:
    vi(Node*)vis;
    void func(Node*ans, Node*nd){
        vis[ans->val]=ans;
        cout<<nd->val<<' ';
        ll sz=nd->neighbors.size();
        ans->neighbors.resize(sz);
        for(ll i=0;i<sz;++i){
            if(vis[nd->neighbors[i]->val]){
                ans->neighbors[i]=vis[nd->neighbors[i]->val];
            }
            else{
                ans->neighbors[i]=new Node(nd->neighbors[i]->val);
                func(ans->neighbors[i], nd->neighbors[i]);
            }
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node){
            return nullptr;
        }
        Node*ans=new Node(node->val);
        vis.assign(101, nullptr);
        func(ans, node);
        return ans;
    }
};