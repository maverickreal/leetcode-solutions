    class Solution {
        private Integer sz;

        boolean func(int[] w, Integer d, Integer m) {
            Integer dReq = 1, cap = 0;
            for (Integer i=0; i < sz; ++i) {
                cap += w[i];
                if (cap > m) {
                    ++dReq;
                    if(dReq>d)
                        return false;
                    cap = w[i];
                }
            }
            return true;
        }

        public int shipWithinDays(int[] w, int d) {
            sz = w.length;
            Integer l = w[0], h = 0;
            // System.out.println(res);
            for (Integer i : w) {
                l = Math.max(l, i);
                h += i;
            }
            Integer res = h;
            while (l <= h) {
                Integer m = l + ((h - l) >> 1);
                if (func(w, d, m)) {
                    res = Math.min(res, m);
                    h = m - 1;
                } else
                    l = m + 1;
            }
            return res;
        }
    }