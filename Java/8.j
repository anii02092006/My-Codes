import java.util.Arrays;

public class BinarySearch {
    public static void main(String[] args) {
        int[] arr = {2, 5, 8, 12, 15};
        int key = 12;
        int idx = Arrays.binarySearch(arr, key);
        System.out.println(idx >= 0 ? "Found at " + idx : "Not Found");
    }
}
