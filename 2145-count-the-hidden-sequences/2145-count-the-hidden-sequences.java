class Solution {
    public static int numberOfArrays(int[] arr, int l, int u) {
        int n = arr.length, mn = Integer.MAX_VALUE, mx = Integer.MIN_VALUE;
        for (int i = 0, j = 0; i < n; ++i) {
            j += arr[i];
            mn = Math.min(j, mn);
            mx = Math.max(mx, j);
        }
        long z=0, tmp=Math.min(u, u - mx);
        tmp-= Math.max(l, l - mn);
        ++tmp;
        if(tmp<z)
            return 0;
        return (int) tmp;
    }
}