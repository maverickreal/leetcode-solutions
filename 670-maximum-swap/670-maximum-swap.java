class Solution {
    public int maximumSwap(int n) {
        int m = n, sz = 0;
        do {
            ++sz;
            m /= 10;
        } while (m > 0);
        int[] arr = new int[sz];
        m = n;
        int ptr = sz - 1;
        do {
            arr[ptr--] = m % 10;
            m /= 10;
        } while (m > 0);
        int[][] mx = new int[sz][2];
        mx[sz - 1][0] = arr[sz - 1];
        mx[sz - 1][1] = sz - 1;
        for (int i = sz - 2; i > -1; --i) {
            mx[i][0] = mx[i + 1][0];
            mx[i][1] = mx[i + 1][1];
            if (arr[i] > mx[i][0]) {
                mx[i][0] = arr[i];
                mx[i][1] = i;
            }
        }
        for (int i = 0; i < sz - 1; ++i) {
            if (arr[i] < mx[i + 1][0]) {
                int tmp = arr[i];
                arr[i] = mx[i + 1][0];
                arr[mx[i + 1][1]] = tmp;
                break;
            }
        }
        int res = arr[sz - 1];
        for (int i = sz - 2; i > -1; --i)
            res += arr[i] * Math.pow(10, sz - i - 1);
        return res;
    }
}