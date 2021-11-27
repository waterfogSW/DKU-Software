#include<stdio.h>
#include<stdlib.h>

/*Bubble sort : Pointer version*/
void bubble_p(long* data, long count) {
  long *i, *last;
  for (last = data+count-1; last > data; last--) {
    for (i = data; i < last; i++) {
      if (*(i+1) < *i) {
        /* swap adjacent elements */
        long t = *(i+1);
        *(i+1) = *i;
        *i = t;
      }
    }
  }
}

int main(){
    long data[10] = {1,7,3,0,4,2,5,9,8,6};

    /*Excute bubble sort*/
    bubble_p(data, 10);
    /*Sort result*/
    for (int i =0; i <10; i++)
    {
        printf("%ld ", *(data+i));
    }
    return 0;

}