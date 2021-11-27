#include<stdio.h>
#define N 3

int* matmul(int* mat1,int* mat2,int* matres){
    int i, j , k; //for loop index
    int sum;

    /*행렬 곱 수행*/
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            sum = 0;
            for (int k = 0; k < N; k++)
            {
				sum += mat1[i*N+k] * mat2[k*N+j];
            }
            matres[i*N+j] = sum;
        }
    }
}

int main(){
    int matres[N*N];
    int mat1[N*N] = {1,2,3,1,2,3,1,2,3};
    int mat2[N*N] = {1,2,3,1,2,3,1,2,3};

    matmul(mat1,mat2,matres);

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%d ", matres[i*N+j]);
        }
        printf("\n");
    }
    return 0;
}