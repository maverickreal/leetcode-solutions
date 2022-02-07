class Solution {
        static private int func(int cur, int move, int push, int min, int sec) {
        char start = '0';
        start += cur;
        String mn = "", sc = "";
        if (min > 0)
            mn += min;
        if (!mn.isEmpty() || sec > 0)
            sc += sec;
        if(sc.equals("0"))
            sc="00";
        if(!mn.isEmpty() && sec<10)
            sc="0"+sec;
        // else
        //     System.out.println(sc);
        int res = 0;
        // if (sc.isEmpty())
        // return res;
        for (char ch : mn.toCharArray()) {
            if (ch != start) {
                start = ch;
                res += move;
            }
            res += push;
        }
        for (char ch : sc.toCharArray()) {
            if (ch != start) {
                start = ch;
                res += move;
            }
            res += push;
        }
        //System.out.println(res);
        return res;
    }

    static public int minCostSetTime(int start, int move, int push, int tar) {
        int min = tar / 60, sec = tar % 60;
        if (tar < 60)
            return func(start, move, push, min, sec);
        if (tar < 100)
            return Math.min(func(start, move, push, min, sec), func(start, move, push, min - 1, sec + 60));
        int res = Integer.MAX_VALUE;
        if (min < 100)
            res = Math.min(res, func(start, move, push, min, sec));
        --min;
        sec += 60;
        if(sec<100)
            res=Math.min(res, func(start, move, push, min, sec));
        return res;
    }
}