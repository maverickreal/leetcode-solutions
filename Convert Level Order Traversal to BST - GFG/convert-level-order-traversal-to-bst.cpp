//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

void preorderTraversal(Node* root)
{
	if (!root)return;
	cout << root->data << " ";
	preorderTraversal(root->left);
	preorderTraversal(root->right); 
}

Node* constructBst(int arr[], int n);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)cin>>arr[i];
        Node *root = constructBst(arr, n);
        preorderTraversal(root);
        cout<<endl;
    }
	return 0; 
}
// } Driver Code Ends


//User function Template for C++


//Function to construct the BST from its given level order traversal.
Node* constructBst(int arr[], int n){
    Node*root=new Node(arr[0]);
    list<tuple<Node*, int, int>>l;
    l.push_back(tuple<Node*, int, int>(root, INT_MIN, root->data));
    l.push_back(tuple<Node*, int, int>(root, root->data, INT_MAX));
    for(int in=1;in<n && !l.empty();++in){
        //cout<<in<<' ';
        Node*par=get<0>(l.front());
        int lb=get<1>(l.front());
        int rb=get<2>(l.front());
        l.pop_front();
        if(arr[in]<=lb || arr[in]>=rb){
            --in;
            continue;
        }
        Node*nd=new Node(arr[in]);
        if(nd->data>par->data){
            par->right=nd;
            l.push_back(tuple<Node*, int, int>(nd, par->data, nd->data));
            l.push_back(tuple<Node*, int, int>(nd, nd->data, rb));
        }
        else{
            par->left=nd;
            l.push_back(tuple<Node*, int, int>(nd, lb, nd->data));
            l.push_back(tuple<Node*, int, int>(nd, nd->data, par->data));
        }
    }
    return root;
}
