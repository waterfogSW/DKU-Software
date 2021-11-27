#include<stdio.h>
#include<stdlib.h>

/*Insertion_sort : Pointer version*/
void insertion_sort(long* data, long count) {
    long *i, *j, temp;
    for(i=data+1; i<data+count; i++){
        temp = *i;
        for(j=i-1; j>=data && *j>temp; j--){
            *(j+1) = *(j);
        }
    *(j+1) = temp;
  }
}

int main(){
    long data[10] = {1,7,3,0,4,2,5,9,8,6};

    /*Excute insertion_sort sort*/
    insertion_sort(data, 10);
    /*Sort result*/
    for (int i =0; i <10; i++)
    {
        printf("%ld ", *(data+i));
    }
    return 0;
}