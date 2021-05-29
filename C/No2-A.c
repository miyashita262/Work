#include<stdio.h>

int main(void){
    int i,j;

    printf("Please fill in number1:");
    scanf("%d",&i);
    printf("please fill in number2:");
    scanf("%d",&j);

    for(i; i <= j; i++){
        if(i % 2 == 0 && i < 0)
        printf("%d:Nagative(Even)\n",i);
        if(i % 2 && i < 0)
        printf("%d:Nagative(Odd)\n",i);
        if(i == 0 )
        printf("%d:Zero(Even)\n",i);
        if(i % 2 ==0 && i > 0)
        printf("%d:Positive(Even)\n",i);
        if(i % 2 && i>0)
        printf("%d:Positive(odd)\n",i);
    }
    return 0;
}