public class MergeSort {
    public static void sort(int[] data) {
        mergeSort(data, 0, data.length-1);
    }
    private static void mergeSort(int[] data, int left, int right) {
        int mid;
        if(left < right){
            mid = (left + right) / 2;;
            mergeSort(data, left, mid);     //Divide Front part
            mergeSort(data, mid+1, right);  //Divide Back part
            merge(data, left, mid, right);  //Merge and Sort
        }
    }

    private static void merge(int[] data, int left, int mid, int right) {
        int i = left;
        int j = mid + 1;
        int k = left;

        int[] temp = new int[data.length];

        /*Compare*/
        while(i <= mid && j <= right){
            if(data[i] <= data[j]){
                temp[k++] = data[i++];
            } else {
                temp[k++] = data[j++];
            }
        }
        
        /*Add remaining parts*/
        while(i <= mid){ temp[k++] = data[i++]; }
        while(j <= right){ temp[k++] = data[j++]; }

        for (int a = left; a <= right; a++) {
            data[a] = temp[a];
        }
    }
}