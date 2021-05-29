#include<stdio.h>

void scanf_d(int *a){
    scanf("%d",a);
    return ;
}

int main (void){
    int x;
    scanf_d(&x);
    printf("a=%d\n",x);
    return 0;
}