/*알고리즘 3분반, 32170578, 김산*/
package report1;
import java.util.Scanner;

public class report1 {

    public static void main(String[] args) {
        /*Scanner Object Initialize*/
        Scanner sc = new Scanner(System.in);

        /*Set Array Size & Initialize*/
        System.out.print("Input number of Integers: ");
        int num = sc.nextInt();
        int[] arr = new int[num];

        /*Input Integers*/
        System.out.print("Input " + num + " Integers: ");
        for (int i = 0; i < arr.length; i++)
            arr[i] = sc.nextInt();

        /*Close Scanner*/
        sc.close();

        /*Print Inputed Integers*/
        System.out.print("Inputed Integers: [ ");
        for(int i: arr){
            System.out.print(i + " ");
        }
        System.out.println("]");

        /*MergeSort*/
        mergeSort(arr, 0, arr.length-1);

        /*Sorted Integers*/
        System.out.print("Inputed Integers: [ ");
        for(int i: arr){
            System.out.print(i + " ");
        }
        System.out.println("]");
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