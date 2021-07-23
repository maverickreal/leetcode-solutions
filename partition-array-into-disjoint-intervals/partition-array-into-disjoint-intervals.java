class Solution {
    public int partitionDisjoint(int[] ar) {
        int sz = ar.length;
        int[] mx = new int[sz];
        int[] mn = new int[sz];

        for (int i = 0, minN = ar[sz - 1], maxN = ar[0]; i < sz; ++i) {
            if (maxN < ar[i])
                maxN = ar[i];
            if (minN > ar[sz - i - 1])
                minN = ar[sz - 1 - i];
            mx[i] = maxN;
            mn[sz - i - 1] = minN;
        }
        int i = -1;
        while (++i <= sz - 1 && mx[i] > mn[i + 1])
            ;
        return i + 1;
    }
}