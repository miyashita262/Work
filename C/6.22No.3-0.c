#include<stdio.h>
#include<stdlib.h>

int*intArr(int n){
    int *arr =(int *)malloc(sizeof(int)*n);
    for(int i =0;i<n; i++){
        arr[i]=i;
    }
    return arr;
}

int main (void){
    int n;
    scanf("%d",&n);
    int *arr= intArr(n);
    for(int i=0; i < n; i++)
    printf("%d\n",arr[i]);
    free(arr);

    return 0;

}