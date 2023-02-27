//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution{
public:
typedef long long ll;
#define vi(x) vector<x>
typedef pair<ll, ll> pi;
#define pb push_back
const ll mod = 1e9 + 7;
const char nl = '\n';

Node* divide(int N, Node *head){
    Node*odd=nullptr, *even=nullptr, *oh=nullptr, *eh=nullptr;
    while(head){
        //cout<<head->data<<' ';
        if((head->data)&1){
            if(oh!=nullptr){
                odd=odd->next=head;
            }
            else{
                oh=odd=head;
            }
        }
        else{
            if(eh!=nullptr){
                even=even->next=head;
            }
            else{
                eh=even=head;
            }
        }
        head=head->next;
    }
    if(eh!=nullptr){
        even->next=oh;
    }
    if(odd!=nullptr){
        odd->next=nullptr;
    }
    return (eh==nullptr?oh:eh);
}
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends