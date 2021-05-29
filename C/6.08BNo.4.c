#include<stdio.h>

void my_swap(int *a, int *b ){
    int k = *a;
    *a = *b;
    *b = k;
}

int main (void){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("a= %d,b=%d\n",a,b);
    my_swap(&a,&b);
    printf("a=%d,b=%d\n",a,b);
    return 0;
}