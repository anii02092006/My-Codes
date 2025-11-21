public class LinearSearch {
    public static void main(String[] args) {
        int[] arr = {3, 8, 1, 7, 9};
        int key = 7;
        for (int i = 0; i < arr.length; i++) {
            if (arr[i] == key) {
                System.out.println("Found at index " + i);
                return;
            }
        }
        System.out.println("Not Found");
    }
}
