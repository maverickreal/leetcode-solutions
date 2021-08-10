/**
 * Definition for a binary tree node. public class TreeNode { int val; TreeNode
 * left; TreeNode right; TreeNode() {} TreeNode(int val) { this.val = val; }
 * TreeNode(int val, TreeNode left, TreeNode right) { this.val = val; this.left
 * = left; this.right = right; } }
 */
class Solution {
    boolean func(TreeNode rt) {
        if (rt == null)
            return true;
        if (func(rt.left))
            rt.left = null;
        if (func(rt.right))
            rt.right = null;
        return (rt.left == null & rt.right == null && rt.val == 0);
    }

    public TreeNode pruneTree(TreeNode rt) {
        return func(rt) ? null : rt;
    }
}