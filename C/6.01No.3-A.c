#include<stdio.h>

int biger(int a, int b);
int myabs(signed int a);
int myabs1(signed int b);

int main(void){
    int a,b;
    scanf("%d",&a);
    scanf("%d",&b);
    printf("a = %d, b = %d\n",a,b);
    printf("%d is greater.\n",biger(a,b));
    printf("myabs(%d) = %d\n" , a , myabs(a));
    printf("myabs1(%d) = %d\n" , b , myabs1(b));
    return 0;
}

int biger(int a, int b){
    int max = a;
    if( b > max )
        max = b;
    return max;
}

int myabs(signed int a){
    int hu =a;
    if(a < 0)
      hu  = a*-1;
    return hu;
}
int myabs1(signed int b){
    int mai =b;
    if(b < 0)
    mai = b*-1;
    return mai;
}

