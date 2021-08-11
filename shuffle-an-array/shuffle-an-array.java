import java.util.Random;

class Solution {
    int[] ar;
    int[] copy;
    Random rand = new Random();

    public Solution(int[] arr) {
        ar = arr.clone();
        copy = arr;
    }

    /** Resets the array to its original configuration and return it. */
    public int[] reset() {
        ar = copy.clone();
        return ar;
    }

    /** Returns a random shuffling of the array. */
    public int[] shuffle() {
        for (int i = 0; i < ar.length; ++i) {
            int in = rand.nextInt(ar.length);
            /*
             * ar[i] += ar[in]; ar[in] = ar[i] - ar[in]; ar[i] -= ar[in];
             */
            int tmp = ar[i];
            ar[i] = ar[in];
            ar[in] = tmp;
        }
        return ar;
    }
}