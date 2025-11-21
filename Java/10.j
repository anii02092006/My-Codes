public class SecondLargest {
    public static void main(String[] args) {
        int[] arr = {12, 35, 1, 10, 34};
        int max = Integer.MIN_VALUE, second = Integer.MIN_VALUE;

        for (int x : arr) {
            if (x > max) {
                second = max;
                max = x;
            } else if (x > second && x != max) {
                second = x;
            }
        }

        System.out.println("Second Largest: " + second);
    }
}
