class pair implements Comparable<pair> {
    Integer f, s, t;

    pair(Integer f, Integer s, Integer t) {
        this.s = s;
        this.f = f;
        this.t = t;
    }

    pair(Integer f, Integer s) {
        this.f = f;
        this.s = s;
    }

    pair() {
    }

    public int compareTo(pair p) {
        return this.t - p.t;
    }

}
class Solution {

    static private ArrayList<pair> dir;

    public int swimInWater(int[][] grid) {
        dir = new ArrayList<>();
        dir.add(new pair(0, 1));
        dir.add(new pair(1, 0));
        dir.add(new pair(0, -1));
        dir.add(new pair(-1, 0));
        final Integer m = grid.length, n = grid[0].length;
        PriorityQueue<pair> pq = new PriorityQueue<>();
        pq.add(new pair(0, 0, grid[0][0]));
        HashMap<Integer, HashSet<Integer>> vis = new HashMap<>();
        for (Integer i = 0; i < m; ++i)
            vis.put(i, new HashSet<>());
        while (!pq.isEmpty()) {
            pair p = pq.poll();
            vis.get(p.f).add(p.s);
            if (p.f == p.s && p.s == n - 1)
                return p.t;
            for (pair pd : dir) {
                Integer x = p.f + pd.f, y = p.s + pd.s;
                if (x < 0 || x >= m || y < 0 || y >= n || vis.get(x).contains(y))
                    continue;
                pq.offer(new pair(x, y, Math.max(p.t, grid[x][y])));
            }
        }
        return -1;
    }
}