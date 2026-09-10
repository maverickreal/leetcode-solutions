function averageOfSubtree(root: TreeNode | null): number {
    const st = new Stack<{ nd: TreeNode, cnt: number, sum: number }>();
    let ans: number = 0;
    st.push({ nd: root, cnt: 1, sum: root.val });

    while (!st.isEmpty()) {
        const top = { ...st.peek() };

        if (top.nd.left) {
            st.push({ nd: top.nd.left, cnt: 1, sum: top.nd.left.val });
            top.nd.left = null;

            continue;
        }

        if (top.nd.right) {
            st.push({ nd: top.nd.right, cnt: 1, sum: top.nd.right.val });
            top.nd.right = null;

            continue;
        }
        const avg = (top.sum / top.cnt) | 0;
        ans += (top.nd.val === avg) ? 1 : 0;
        st.pop();
        const pre = st.peek();

        if (pre) {
            pre.sum += top.sum
            pre.cnt += top.cnt;
        }
    }

    return ans;
};