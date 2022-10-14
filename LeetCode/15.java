import java.util.*;

class Solution {
    int[] arr;

    private void mergeSort(int l, int r) {
        if (l < r) {
            int mid = (l + r) / 2;

            mergeSort(l, mid);
            mergeSort(mid+1, r);
            this.merge(l, mid, r);
        }
    }

    private void merge(int l, int m, int r) {
        int[] s = new int[3001];
        int i=l, j=m+1;
        int k=l;

        while (i <= m && j <= r) {
            if (arr[i] < arr[j]) s[k++] = arr[i++];
            else s[k++] = arr[j++];
        }

        while (i <= m) s[k++] = arr[i++];
        while (j <= r) s[k++] = arr[j++];

        for (i=l; i<=r; i++) arr[i] = s[i];
    }

    public List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> result = new ArrayList<>();
        HashSet<List<Integer>> dup = new HashSet<List<Integer>>();

        arr = nums;
        this.mergeSort(0, nums.length-1);

        int size = arr.length;

        for (int m=0; m<size; m++) {
            int c = arr[m];
            int l=0, r=size-1;

            System.out.println("=========== " + m + ": " + c);

            while (l < m && m < r) {
                int v = c + arr[l] + arr[r];

                System.out.println("[" + l + "]:" + arr[l] + " + " + "[" + m + "]:" + arr[m] + " + " + "[" + r + "]:" + arr[r] + " = " + v);

                if (v == 0) {
                    System.out.println("---------------------------------> " + l + " " + m + " " + r);
                    Integer[] data = {arr[l], c, arr[r]};
                    List<Integer> tmp = new ArrayList<>(Arrays.asList(data));

                    if (dup.add(tmp) == true) result.add(tmp);
                    l++;
                    r--;
                } else if (v < 0) l++;
                else r--;
            }

            System.out.println();
        }

        return result;
    }
}

class code1 {
    public static void main(String[] args) {
        Solution s = new Solution();

        int n[][] = {
            {-1,0,1,2,-1,-4},
            {0,1,1},
            {0,0,0},
            {-2,0,1,1,2}
        };

        for (int i=0; i<n.length; i++) {
            System.out.println("************************************************************ RESULT : " + s.threeSum(n[i]) + " ************************************************************");
            System.out.println();
        }
    }
}