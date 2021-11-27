public class Sort {
    public static void main(String[] args) {
        int[] n = {1000, 5000, 10000, 20000, 50000, 100000};

        long start;
        long stop;

        long mergeSum = 0;
        long quickSum = 0;

        double mergesortTime;
        double quicksortTime;

        for (int i = 0; i < n.length; i++) {
            for (int j = 0; j < 10; j++) {
                int []arr1 = Generater.genNumber(n[i]);
                int []arr2 = arr1;
    
                start = System.currentTimeMillis();
                MergeSort.sort(arr1);
                stop = System.currentTimeMillis();
                mergeSum += stop - start;
            
                start = System.currentTimeMillis();
                QuickSort.sort(arr2);
                stop = System.currentTimeMillis();
                quickSum += stop - start;
            }
    
            mergesortTime = mergeSum / 10.0;
            quicksortTime = quickSum / 10.0;
            
            System.out.println("------------------");
            System.out.println("Samples " + n[i]);
            System.out.println("MergeSort : " + mergesortTime);
            System.out.println("QuickSort : " + quicksortTime);
            System.out.println("------------------");
        }
    }
    
}