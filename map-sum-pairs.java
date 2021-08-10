class MapSum {
    HashMap<String, Integer> map, map2;

    /** Initialize your data structure here. */
    public MapSum() {
        map = new HashMap();
        map2 = new HashMap();
    }

    public void insert(String key, int val) {
        int dif = val - map2.getOrDefault(key, 0);
        map2.put(key, val);
        String s = "";
        for (char c : key.toCharArray()) {
            s += c;
            map.put(s, dif + map.getOrDefault(s,0));
        }
    }

    public int sum(String prefix) {
        return map.getOrDefault(prefix, 0);
    }
}

/**
 * Your MapSum object will be instantiated and called as such: MapSum obj = new
 * MapSum(); obj.insert(key,val); int param_2 = obj.sum(prefix);
 */