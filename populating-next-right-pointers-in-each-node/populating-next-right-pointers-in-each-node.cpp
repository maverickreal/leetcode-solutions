class Solution {
#define tn Node
public:
    Node* connect(Node* rt) {
        if (!rt || !(rt->left || rt->right))
            return rt;
        queue<tn*>q;
        q.push(rt->left);
        q.push(rt->right);
        while (!q.empty()) {
            queue<tn*>tmp;
            while (!q.empty()) {
                tn* nd = q.front();
                q.pop();
                if (!q.empty())
                    nd->next = q.front();
                if (nd->left)
                    tmp.push(nd->left);
                if (nd->right)
                    tmp.push(nd->right);
            }
            q = tmp;
        }
        return rt;
    }
};