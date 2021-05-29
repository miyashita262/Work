#include<stdio.h>

void wasa(int*wa , int*sa , int x, int y){
    *wa = x + y;
    *sa = x - y;
}

int main (void){
    int x,y,wa,sa;
    scanf("%d",&x);
    scanf("%d",&y);
    printf("x = %d , y = %d\n",x,y);
    wasa(&wa,&sa,x,y);
    printf("wa = x+y %d\nsa = x-y = %d\n",wa,sa);

    return 0;
}
