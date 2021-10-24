    class Solution {

        static private class group {
            public Integer f;
            public Integer s;

            public group(Integer f, Integer s) {
                this.f = f;
                this.s = s;
            }
        }

        static private ArrayList<group> dir;

        static private Integer m, n;

        static private void dfs(ArrayList<ArrayList<Integer>> g, Integer r, Integer c) {
            Integer cur = g.get(r).get(c);
            g.get(r).set(c, 0 - cur);
            Integer cnt = 0;
            for (group p : dir) {
                Integer x = r + p.f, y = c + p.s;
                if (x < 0 || y < 0 || x == m || y == n)
                    continue;
                if (g.get(x).get(y) < 0) {
                    ++cnt;
                    continue;
                }
                if (g.get(x).get(y) != cur)
                    continue;
                dfs(g, x, y);
                ++cnt;
            }
            //System.out.println(r.toString() + "  " + c.toString() + "  " + cnt.toString());
            if (cnt == 4)
                g.get(r).set(c, cur);
        }

        public int[][] colorBorder(int[][] Ar, int r, int c, int col) {

            dir = new ArrayList<>(4);
            dir.add(new group(0, 1));
            dir.add(new group(0, -1));
            dir.add(new group(1, 0));
            dir.add(new group(-1, 0));
            ArrayList<ArrayList<Integer>> ar = new ArrayList<>();
            for (int[] x : Ar) {
                ArrayList<Integer> tmp = new ArrayList<>();
                for (int y : x)
                    tmp.add(y);
                ar.add(tmp);
            }
            m = ar.size();
            n = ar.get(0).size();
            dfs(ar, r, c);
            // System.out.println(ar);
            for (Integer i = 0; i < m; ++i) {
                for (Integer j = 0; j < n; ++j) {
                    Ar[i][j] = ar.get(i).get(j);
                    if (Ar[i][j] < 0)
                        Ar[i][j] = col;
                }
            }
            return Ar;
        }
    }