
/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode(int x) { val = x; }
 * }
 */

import java.util.Stack;

class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        Stack<TreeNode> st = new Stack<TreeNode>();
        Stack<TreeNode> st2 = new Stack<TreeNode>();
        st.push(root);
        st2.push(root);
        while (st.peek() != null && st.peek().val != p.val) {
            if (st.peek().val == q.val)
                return st.peek();
            if (st.peek().val > p.val)
                st.push(st.peek().left);
            else
                st.push(st.peek().right);
        }
        //System.out.println('1');
        while (st2.peek() != null && st2.peek().val != q.val) {
            if (st2.peek().val == p.val)
                return st2.peek();
            if (st2.peek().val > q.val)
                st2.push(st2.peek().left);
            else
                st2.push(st2.peek().right);
        }
        //System.out.println('2');
        while (st.size() < st2.size())
            st2.pop();
        while (st2.size() < st.size())
            st.pop();
        while (!st.empty() && !st2.empty() && st.peek().val != st2.peek().val) {
            st.pop();
            st2.pop();
        }
        return (st.empty() ? st2.peek() : st.peek());
    }
}