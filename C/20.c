#include<stdio.h>

int func(int *x,int *y){
    (*x)=(*x)*2;
    (*y)=(*y)*3;
    return((*x)+(*y));
}
int main(void){
    int a=2;
    int b=3;
    int c;
    c=func(&a,&b);
    printf("%d,%d,%d\n",a,b,c);

   
}


