    class Solution {
        public int minimumSize(int[] ar, int n) {
            HashMap<Integer, Integer> ump = new HashMap<>();
            Integer i = 1, j = 0, res = 0;
            for (Integer h : ar) {
                j = Math.max(j, h);
                if (ump.containsKey(h))
                    ump.put(h, 1 + ump.get(h));
                else
                    ump.put(h, 1);
            }
            while (i <= j) {
                Integer m = i + ((j - i) >> 1);
                Integer num = 0;
                for (Map.Entry<Integer, Integer> e : ump.entrySet()) {
                    if (e.getKey() <= m)
                        continue;
                    num += e.getValue() * ((e.getKey() / m) - (e.getKey() % m > 0 ? 0 : 1));
                    if (num > n)
                        break;
                }
                if (num > n)
                    i = m + 1;
                else {
                    res = m;
                    j = m - 1;
                }
            }
            return res;
        }
    }