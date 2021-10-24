class Solution {

    public Solution() {
    }

        static private class group {
        public Integer f;
        public Integer s;
    
        public group(Integer f, Integer s) {
        this.f = f;
        this.s = s;
        }
        }

    static private Integer m, n;

    static private group func(ArrayList<ArrayList<Integer>> g, Integer r, Integer c) {
        if (r <0 || c <0 || r >m-1 || c>n-1 || g.get(r).get(c)==0)
            return new group(0,1);
        group ans=new group(1,1);
        if (r == m - 1 || r == 0 || c == n - 1 || c == 0)
            ans.s=0;
        g.get(r).set(c, 0);
        group res = func(g, r + 1, c);
        if (res.s == 0)
        ans.s=0;
        ans.f+=res.f;
        res = func(g, r - 1, c);
        if (res.s == 0)
        ans.s=0;
        ans.f+=res.f;
        res = func(g, r, c + 1);
        if (res.s == 0)
        ans.s=0;
        ans.f+=res.f;
        res = func(g, r, c - 1);
        if (res.s == 0)
        ans.s=0;
        ans.f+=res.f;
        //System.out.println(r.toString()+"  "+c.toString()+"  "+res.f.toString()+"  "+res.s.toString());
        return ans;
    }

    public int numEnclaves(int[][] g) {
        ArrayList<ArrayList<Integer>> ar = new ArrayList<>();
        for (int[] x : g) {
            ArrayList<Integer> tmp = new ArrayList<>();
            for (Integer y : x)
                tmp.add(y);
            ar.add(tmp);
        }
        m = ar.size();
        n = ar.get(0).size();
        Integer res = 0;
        for (Integer i = 0; i < m; ++i) {
            for (Integer j = 0; j < n; ++j) {
                group tmp = func(ar, i, j);
                if (tmp.s==1){
                    //System.out.println(i.toString() + " " + j.toString()+"  "+tmp);
                    res += tmp.f;
                }
            }
        }
        return res;
    }
}
