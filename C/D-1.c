#include<stdio.h>

int main(void){
    int a = 43;
    int b =043;
    int c =0x43;
    int d ='T';

    printf("%%d: a=%d, b=%d, c=%d, d=%d\n", a,b,c,d);
    printf("%%o: a=%o, b=%o, c=%o, d=%o\n", a,b,c,d);
    printf("%%x: a=%x, b=%x, c=%x, d=%x\n", a,b,c,d);
    printf("%%c: a=%c, b=%c, c=%c, d=%c\n", a,b,c,d);
}