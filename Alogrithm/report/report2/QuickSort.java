public class QuickSort {
    public static void sort(int[] data) {
        quicksort(data, 0, data.length-1);
    }

    private static void quicksort(int[] data, int p, int q) {
        if(p < q) {
            int pivot = partition(data, p, q+1);
            quicksort(data, p, pivot-1);
            quicksort(data,pivot+1,q);
        }
    }

    private static int partition(int[] data, int m, int p) {
        int v=data[m]; int i=m, j=p;
        do {
            do i++;
            while (data[i] < v);
            do j--;
            while (data[j] > v);
            if (i < j) interchange(data, i, j);
        } while (i < j);
        data[m] = data[j]; 
        data[j] = v; 
        return(j);
    }
 

    private static void interchange(int[] data, int i, int j) {
        int temp = data[i];
        data[i] = data[j];
        data[j] = temp;
    }
}
